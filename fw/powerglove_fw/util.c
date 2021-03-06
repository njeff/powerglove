#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "util.h"
#include "nrf_gpio.h"
#include "nrf.h"
#include "nrf_drv_pwm.h"
#include "nrfx_saadc.h"

#include "millis.h"
#include "buckler.h"

static nrf_drv_pwm_t m_pwm0 = NRF_DRV_PWM_INSTANCE(0);

static nrf_pwm_values_individual_t seq_values[] = {{500, 500, 0, 0}};
nrf_pwm_sequence_t const seq =
{
    .values.p_common = seq_values,
    .length          = NRF_PWM_VALUES_LENGTH(seq_values),
    .repeats         = 0,
    .end_delay       = 0
};

void servoInit() {
  nrf_gpio_cfg_output(SERVO_0);
  nrf_gpio_cfg_output(SERVO_1);

  uint32_t err_code;
  nrf_drv_pwm_config_t const config0 =
  { 
    .output_pins =
    {
        SERVO_0 | NRF_DRV_PWM_PIN_INVERTED,   // channel 0
        SERVO_1 | NRF_DRV_PWM_PIN_INVERTED,   // channel 1
        NRF_DRV_PWM_PIN_NOT_USED,             // channel 2
        NRF_DRV_PWM_PIN_NOT_USED,             // channel 3
    },
    .irq_priority = APP_IRQ_PRIORITY_LOWEST,
    .base_clock   = NRF_PWM_CLK_1MHz,
    .count_mode   = NRF_PWM_MODE_UP,
    .top_value    = 20000,
    .load_mode    = NRF_PWM_LOAD_INDIVIDUAL,
    .step_mode    = NRF_PWM_STEP_AUTO
  };
  err_code = nrf_drv_pwm_init(&m_pwm0, &config0, NULL);
  APP_ERROR_CHECK(err_code);

  nrf_drv_pwm_simple_playback(&m_pwm0, &seq, 1, NRF_DRV_PWM_FLAG_LOOP);
}

// negative angle disables the servo (makes it free spinning)
void setServoAngle(uint8_t servo_number, int16_t angle) {
  // Angle input in degrees [0, 180]
  // servo valid count range from 500 to 2500 (0.5ms to 2.5ms)
  // 500 -  2.9V on FB pin
  // 2500 - 0.27V on FB pin
  uint32_t pulse_width = 0;
  if (angle > 180) {
    angle = 180;
  }
  if (angle >= 0) {
    pulse_width = 500 + (uint32_t)angle * 2000/180;
  }

  if (servo_number == 0) {
    seq_values->channel_0 = pulse_width;
  } else {
    seq_values->channel_1 = pulse_width;
  }

  nrf_drv_pwm_simple_playback(&m_pwm0, &seq, 1, NRF_DRV_PWM_FLAG_LOOP);
}

// Feedback pin voltage to servo angle
uint8_t fbVoltToAngle(float voltage) {
  // 0.23 to 180 deg, 3 to 0 deg
  const float lowerV = 0.27;
  const float upperV = 3;
  if (voltage < lowerV) {
    voltage = lowerV;
  }
  if (voltage > upperV) {
    voltage = upperV;
  }
  return (uint8_t)(180.0 - 180.0*(voltage - lowerV)/(upperV - lowerV));
}

// callback for SAADC events
void saadc_callback (nrfx_saadc_evt_t const * p_event) {
  // don't care about adc callbacks
}

void adcInit() {
  uint32_t error_code;
  // initialize analog to digital converter
  nrfx_saadc_config_t saadc_config = NRFX_SAADC_DEFAULT_CONFIG;
  saadc_config.resolution = NRF_SAADC_RESOLUTION_12BIT;
  error_code = nrfx_saadc_init(&saadc_config, saadc_callback);
  APP_ERROR_CHECK(error_code);

  // initialize analog inputs
  // configure with 0 as input pin for now
  // Battery voltage reading pin
  nrf_saadc_channel_config_t channel_config = NRFX_SAADC_DEFAULT_CHANNEL_CONFIG_SE(0);
  channel_config.gain = NRF_SAADC_GAIN1_6; // input gain of 1/6 Volts/Volt, multiply incoming signal by (1/6)
  channel_config.reference = NRF_SAADC_REFERENCE_INTERNAL; // 0.6 Volt reference, input after gain can be 0 to 0.6 Volts

  // specify input pin and initialize that ADC channel
  channel_config.pin_p = BATTERY_PIN;
  error_code = nrfx_saadc_channel_init(BATTERY_CHANNEL, &channel_config);
  APP_ERROR_CHECK(error_code);

  // Servo FB reading pin
  nrf_saadc_channel_config_t channel_config2 = NRFX_SAADC_DEFAULT_CHANNEL_CONFIG_SE(1);
  channel_config2.gain = NRF_SAADC_GAIN1_6; // input gain of 1/6 Volts/Volt, multiply incoming signal by (1/6)
  channel_config2.reference = NRF_SAADC_REFERENCE_INTERNAL; // 0.6 Volt reference, input after gain can be 0 to 0.6 Volts

  // specify input pin and initialize that ADC channel
  channel_config2.pin_p = SERVO_FB_PIN;
  error_code = nrfx_saadc_channel_init(SERVO_FB_CHANNEL, &channel_config2);
  APP_ERROR_CHECK(error_code);
}

float readBattery() {
  // returns the absolute battery voltage
  nrf_saadc_value_t val;
  ret_code_t error_code = nrfx_saadc_sample_convert(BATTERY_CHANNEL, &val);
  APP_ERROR_CHECK(error_code);
  
  // 3x for the voltage divider
  return 3 * 3.6 * val / (1 << 12);
}

float readServoFB() {
  // returns the voltage of the servo FB pin
  nrf_saadc_value_t val;
  ret_code_t error_code = nrfx_saadc_sample_convert(SERVO_FB_CHANNEL, &val);
  APP_ERROR_CHECK(error_code);
  
  // 3x for the voltage divider
  return 3.6 * val / (1 << 12);
}

void buttonInit() {
   nrf_gpio_cfg(BUCKLER_BUTTON0, NRF_GPIO_PIN_DIR_INPUT, 
                NRF_GPIO_PIN_INPUT_CONNECT, NRF_GPIO_PIN_NOPULL,
                NRF_GPIO_PIN_S0S1, NRF_GPIO_PIN_NOSENSE);
}

static uint32_t last_press_time = 0;
static bool down = false;

bool readButton(uint32_t *hold_duration) {
  // returns true if the button was just *released* on this cycle
  // implements debouncing
  uint32_t hold_time = compareMillis(last_press_time, millis());
  // if just pressed/released ignore all transitions for the next 100ms
  if (hold_time > 100) {
    if (!nrf_gpio_pin_read(BUCKLER_BUTTON0)) {
      // if button is down, and not already down
      if (!down) {
        // record the start time
        last_press_time = millis();
        down = true;
      }
      return false;
    } else {
      if (down) {
        *hold_duration = hold_time;
        last_press_time = millis();
        down = false;
        return true;
      }
      down = false;
    }
  }
  return false;
}
#include <stdio.h>
#include <stdint.h>

#include "util.h"
#include "nrf_gpio.h"
#include "nrf.h"
#include "nrf_drv_pwm.h"

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

void setServoAngle(uint8_t servo_number, uint8_t angle) {
  // Angle input in degrees
  // servo valid count range from 500 to 2500 (0.5ms to 2.5ms)
  // 500 -  2.9V on FB pin
  // 2500 - 0.27V on FB pin
  if (servo_number == 0) {
    seq_values->channel_0 = 500 + (uint32_t)angle * 2000/180;
  } else {
    seq_values->channel_1 = 500 + (uint32_t)angle * 2000/180;
  }
  nrf_drv_pwm_simple_playback(&m_pwm0, &seq, 1, NRF_DRV_PWM_FLAG_LOOP);
}
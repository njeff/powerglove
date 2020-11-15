// Blink app
//
// Blinks the LEDs on Buckler

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "app_error.h"
#include "nrf.h"
#include "nrf_delay.h"
#include "nrfx_gpiote.h"
#include "nrf_gpio.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"
#include "nrf_pwr_mgmt.h"
#include "nrf_twi_mngr.h"
#include "nrf_serial.h"

#include "buckler.h"
#include "drv2605l.h"

// LED array
static uint8_t LEDS[3] = {BUCKLER_LED0, BUCKLER_LED1, BUCKLER_LED2};

NRF_TWI_MNGR_DEF(twi_mngr_instance, 5, 0);

int main(void) {
  ret_code_t error_code = NRF_SUCCESS;

  // initialize i2c master (two wire interface)
  nrf_drv_twi_config_t i2c_config = NRF_DRV_TWI_DEFAULT_CONFIG;
  i2c_config.scl = BUCKLER_SENSORS_SCL;
  i2c_config.sda = BUCKLER_SENSORS_SDA;
  i2c_config.frequency = NRF_TWIM_FREQ_100K;
  error_code = nrf_twi_mngr_init(&twi_mngr_instance, &i2c_config);
  APP_ERROR_CHECK(error_code);

  // initialize GPIO driver
  if (!nrfx_gpiote_is_init()) {
    error_code = nrfx_gpiote_init();
  }
  APP_ERROR_CHECK(error_code);

  // configure leds
  // manually-controlled (simple) output, initially set
  nrfx_gpiote_out_config_t out_config = NRFX_GPIOTE_CONFIG_OUT_SIMPLE(true);
  for (int i=0; i<3; i++) {
    error_code = nrfx_gpiote_out_init(LEDS[i], &out_config);
    APP_ERROR_CHECK(error_code);
  }

  initDRV2605(&twi_mngr_instance);

  // try haptic
  DRV2605_setWaveform(0, 10);
  DRV2605_setWaveform(1, 0);
  DRV2605_go();
  nrf_delay_ms(500);

  DRV2605_setWaveform(0, 30);
  DRV2605_setWaveform(1, 0);
  DRV2605_go();
  nrf_delay_ms(500);

  // loop forever
  while (1) {
    for (int i=0; i<3; i++) {
      nrf_gpio_pin_toggle(LEDS[i]);
      nrf_delay_ms(500);
    }
  }
}


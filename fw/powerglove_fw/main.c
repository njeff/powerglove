// Powerglove Firmware

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
#include "nrf_drv_spi.h"
#include "display.h"
#include "app_timer.h"

#include "buckler.h"
#include "drv2605l.h"
#include "vl53l0x.h"
#include "millis.h"
#include "util.h"
#include "states.h"

// LED array
static uint8_t LEDS[3] = {BUCKLER_LED0, BUCKLER_LED1, BUCKLER_LED2};

NRF_TWI_MNGR_DEF(twi_mngr_instance, 5, 0);

glove_state_t (*pStateFunc)();
glove_state_t state;

int main(void) {
  ret_code_t error_code = NRF_SUCCESS;

  // initialize timer, necessary for the ToF sensor
  millisInit();

  // initialize servo
  servoInit();
  setServoAngle(0, -1);

  // initialize ADC reading for battery and servo FB
  adcInit();

  buttonInit();

  // initialize i2c master (two wire interface)
  nrf_drv_twi_config_t i2c_config = NRF_DRV_TWI_DEFAULT_CONFIG;
  i2c_config.scl = BUCKLER_SENSORS_SCL;
  i2c_config.sda = BUCKLER_SENSORS_SDA;
  i2c_config.frequency = NRF_TWIM_FREQ_100K;
  error_code = nrf_twi_mngr_init(&twi_mngr_instance, &i2c_config);
  APP_ERROR_CHECK(error_code);

  // initialize display
  nrf_drv_spi_t spi_instance = NRF_DRV_SPI_INSTANCE(1);
  nrf_drv_spi_config_t spi_config = {
    .sck_pin = BUCKLER_LCD_SCLK,
    .mosi_pin = BUCKLER_LCD_MOSI,
    .miso_pin = BUCKLER_LCD_MISO,
    .ss_pin = BUCKLER_LCD_CS,
    .irq_priority = NRFX_SPI_DEFAULT_CONFIG_IRQ_PRIORITY,
    .orc = 0,
    .frequency = NRF_DRV_SPI_FREQ_4M,
    .mode = NRF_DRV_SPI_MODE_2,
    .bit_order = NRF_DRV_SPI_BIT_ORDER_MSB_FIRST
  };
  error_code = nrf_drv_spi_init(&spi_instance, &spi_config, NULL, NULL);
  APP_ERROR_CHECK(error_code);
  display_init(&spi_instance);
  //display_write("Hello, Human!", DISPLAY_LINE_0);

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

  // init haptic
  initDRV2605(&twi_mngr_instance);

  // try ToF
  VL53L0X_init(true, &twi_mngr_instance);
  VL53L0X_startContinuous(100);
  

  // loop forever
  state = OFF;
  pStateFunc = state_map[state];
  state_data_t state_info;
  state_info.cal = 0;

  char buf[16];
  while (1) {
    // update all state variables
    state_info.dist = VL53L0X_readRangeContinuousMillimeters();
    state_info.voltage = readBattery();
    state_info.pressed = readButton();
    
    // do state functions
    state = pStateFunc(&state_info);
    pStateFunc = state_map[state];

    nrf_delay_ms(100);
  }
}


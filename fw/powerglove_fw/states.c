#include "states.h"

#include "nrf_gpio.h"
#include "nrf_delay.h"
#include "drv2605l.h"
#include "display.h"
#include "util.h"

glove_state_t (*state_map[])(state_data_t *) = {
  off_state,
  shutting_down_state
};

glove_state_t off_state(state_data_t *state_data) {
  //display_write("0", DISPLAY_LINE_0);
  //DRV2605_setWaveform(0, 83);
  //DRV2605_setWaveform(1, 71);
  //DRV2605_setWaveform(2, 0);
  //DRV2605_go();
  //setServoAngle(0, 180);
  return SHUTTING_DOWN;
}

glove_state_t shutting_down_state(state_data_t *state_data) {
  //display_write("1", DISPLAY_LINE_0);
  //DRV2605_setWaveform(0, 10);
  //DRV2605_setWaveform(1, 0);
  //DRV2605_go();
  if (state_data->dist > 500) {
  	setServoAngle(0, 180);
  } else if (state_data->dist < 50) {
  	setServoAngle(0, 0);
  } else {
  	setServoAngle(0, (state_data->dist - 50) * 180 / 450);
  }
  return OFF;
}

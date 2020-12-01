#include "states.h"

#include <stdbool.h>

#include "nrf_gpio.h"
#include "nrf_delay.h"
#include "drv2605l.h"
#include "display.h"
#include "util.h"

glove_state_t (*state_map[])(state_data_t *) = {
  off_state,
  calibration_state,
  active_state,
  shutting_down_state
};

static char buf[16];
glove_state_t off_state(state_data_t *state_data) {
  sprintf(buf, "Off. Batt:%2.1f", state_data->voltage);
  display_write(buf, DISPLAY_LINE_0);
  sprintf(buf, "ms: %lu", millis());
  display_write(buf, DISPLAY_LINE_1);
  setServoAngle(0, -1);
  if (state_data->pressed) {
    if (state_data->cal == 0) {
      return CALIBRATION;
    } else {
      return ACTIVE;
    }
  }
  return OFF;
}

// calibrate the lower and upper limits
glove_state_t calibration_state(state_data_t *state_data) {
  setServoAngle(0, -1);
  display_write("Calibrating.", DISPLAY_LINE_0);

  uint8_t angle = fbVoltToAngle(readServoFB());
  if (state_data->cal == 0) {
    sprintf(buf, "Lower Ang, %d", angle);
  } else if (state_data->cal == 1) {
    sprintf(buf, "Upper Ang, %d", angle);
  }
  
  display_write(buf, DISPLAY_LINE_1);

  if (state_data->pressed) {
    if (state_data->cal == 0) {
      state_data->lower_angle = angle;
      state_data->cal = 1;
      return CALIBRATION;
    } else if (state_data->cal == 1) {
      state_data->upper_angle = angle;
      state_data->cal = 2;
      return ACTIVE;
    }
  }
  return CALIBRATION;
}

glove_state_t active_state(state_data_t *state_data) {
  sprintf(buf, "Act. Batt:%2.1f", state_data->voltage);
  display_write(buf, DISPLAY_LINE_0);
  display_write("Running!", DISPLAY_LINE_1);
  if (state_data->pressed) {
    return OFF;
  }

  // test ramp up and down
  DRV2605_setWaveform(0, 83);
  DRV2605_setWaveform(1, 71);
  DRV2605_setWaveform(2, 0);
  DRV2605_go();

  if (state_data->dist > 500) {
    setServoAngle(0, state_data->upper_angle);
  } else if (state_data->dist < 50) {
    setServoAngle(0, state_data->lower_angle);
  } else {
    setServoAngle(0, (state_data->dist - 50) * 
      (state_data->upper_angle - state_data->lower_angle) / 450 + state_data->lower_angle);
  }

  return ACTIVE;
}

glove_state_t shutting_down_state(state_data_t *state_data) {
  //display_write("1", DISPLAY_LINE_0);
  //DRV2605_setWaveform(0, 10);
  //DRV2605_setWaveform(1, 0);
  //DRV2605_go();
  
  return OFF;
}

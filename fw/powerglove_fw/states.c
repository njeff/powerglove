#include "states.h"

#include <stdbool.h>
#include <math.h>

#include "nrf_gpio.h"
#include "nrf_delay.h"
#include "drv2605l.h"
#include "lsm9ds1.h"
#include "display.h"
#include "util.h"
#include "millis.h"

glove_state_t (*state_map[])(state_data_t *) = {
  off_state,
  calibration_state,
  active_state,
  sleep_state,
  lp_active_state
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
      // if held down for > 1 sec, go to lower power active
      if (state_data->hold_time > 1000) {
        return LOW_POWER_ACTIVE;
      } else {
        if (state_data->voltage > 7) {
          return ACTIVE;
        } else {
          display_write("Low battery!", DISPLAY_LINE_1);
          nrf_delay_ms(1000);
        }
      }
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
    sprintf(buf, "Close Ang, %d", angle);
  } else if (state_data->cal == 1) {
    sprintf(buf, "Far Ang, %d", angle);
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

static bool moving = true;
static uint32_t last_move_time = 0;
glove_state_t active_state(state_data_t *state_data) {
  const int lowerDist = 50;
  const int upperDist = 500;
  const float gyro_thresh = 5;

  sprintf(buf, "Act. Batt:%2.1f", state_data->voltage);
  display_write(buf, DISPLAY_LINE_0);
  display_write("Running!", DISPLAY_LINE_1);
  lsm9ds1_measurement_t gyro_m = lsm9ds1_read_gyro();
  //printf("%2.1f, %2.1f, %2.1f\n", fabs(gyro_m.x_axis), fabs(gyro_m.y_axis), fabs(gyro_m.z_axis));

  if (fabs(gyro_m.x_axis) < gyro_thresh && 
      fabs(gyro_m.y_axis) < gyro_thresh && 
      fabs(gyro_m.z_axis) < gyro_thresh) {
    if (moving) {
      moving = false;
      last_move_time = millis();
    }
  } else {
    moving = true;
  }
  // after 10 sec of inactivity, sleep
  if (!moving && compareMillis(last_move_time, millis()) > 10000) {
    setServoAngle(0, -1);
    return SLEEP;
  }

  if (state_data->pressed) {
    return OFF;
  }

  if (state_data->voltage < 7) {
    display_write("Low battery!", DISPLAY_LINE_1);
    nrf_delay_ms(1000);
    return OFF;
  }

  // test ramp up and down
  DRV2605_setWaveform(0, 83);
  DRV2605_setWaveform(1, 71);
  DRV2605_setWaveform(2, 0);
  DRV2605_go();

  if (state_data->dist > upperDist) {
    setServoAngle(0, state_data->upper_angle);
  } else if (state_data->dist < lowerDist) {
    setServoAngle(0, state_data->lower_angle);
  } else {
    setServoAngle(0, (state_data->dist - lowerDist) * 
      (state_data->upper_angle - state_data->lower_angle) / (upperDist - lowerDist) + state_data->lower_angle);
  }

  return ACTIVE;
}

// if motion is not detected for awhile
glove_state_t sleep_state(state_data_t *state_data) {
  const float gyro_thresh = 5;
  display_write("Sleeping.", DISPLAY_LINE_0);
  display_write("Move to wake.", DISPLAY_LINE_1);
  setServoAngle(0, -1);

  lsm9ds1_measurement_t gyro_m = lsm9ds1_read_gyro();
  if (fabs(gyro_m.x_axis) > gyro_thresh || 
      fabs(gyro_m.y_axis) > gyro_thresh || 
      fabs(gyro_m.z_axis) > gyro_thresh) {
    // not sure if I like these somewhat global variables being set like this
    // between functions, but don't think they belong in the state data struct
    moving = true; 
    return ACTIVE;
  }

  if (state_data->pressed) {
    moving = true; 
    return OFF;
  }

  return SLEEP;
}

glove_state_t lp_active_state(state_data_t *state_data) {
  display_write("Low Power Mode", DISPLAY_LINE_0);
  
  if (state_data->pressed) {
    return OFF;
  }

  const int lowerDist = 50;
  const int upperDist = 500;

  // clamp
  int d = fmin(fmax(state_data->dist, lowerDist), upperDist);
  int levels = (d - lowerDist) * 8 / (upperDist - lowerDist);
  sprintf(buf, "lvl: %d", levels);
  display_write(buf, DISPLAY_LINE_1);

  if (levels < 2) {
    DRV2605_setWaveform(0, 1); // 100% strong click
  } else if (levels < 6) {
    DRV2605_setWaveform(0, 2); // 60% strong click
  } else {
    DRV2605_setWaveform(0, 3); // 30% strong click
  }
  DRV2605_setWaveform(1, 0);
  DRV2605_go();

  return LOW_POWER_ACTIVE;
}
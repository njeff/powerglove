#ifndef _STATES_H
#define _STATES_H

#include <stdint.h>
#include <stdbool.h>

// enum must match the state map!
typedef enum {
  OFF,
  CALIBRATION,
  ACTIVE,
  SLEEP,
  LOW_POWER_ACTIVE
} glove_state_t;

typedef struct s_data {
  int cal;
  int dist;
  float voltage;
  bool pressed;
  uint8_t lower_angle;
  uint8_t upper_angle;
  uint32_t hold_time;
} state_data_t;

glove_state_t off_state(state_data_t *state_data);
glove_state_t calibration_state(state_data_t *state_data);
glove_state_t active_state(state_data_t *state_data);
glove_state_t sleep_state(state_data_t *state_data);
glove_state_t lp_active_state(state_data_t *state_data);

extern glove_state_t (*state_map[])(state_data_t *);

#endif
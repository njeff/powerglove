#ifndef _STATES_H
#define _STATES_H

#include <stdbool.h>

// enum must match the state map!
typedef enum {
  OFF,
  ACTIVE,
  SHUTTING_DOWN,
} glove_state_t;

typedef struct s_data {
  int dist;
  float voltage;
  bool pressed;
} state_data_t;

glove_state_t off_state(state_data_t *state_data);
glove_state_t active_state(state_data_t *state_data);
glove_state_t shutting_down_state(state_data_t *state_data);

extern glove_state_t (*state_map[])(state_data_t *);

#endif
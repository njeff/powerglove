#ifndef _STATES_H
#define _STATES_H

// enum must match the state map!
typedef enum {
  OFF,
  SHUTTING_DOWN,
  MAIN_SENSE
} glove_state_t;

typedef struct s_data {
  int dist;
  float voltage;
} state_data_t;

glove_state_t off_state(state_data_t *state_data);
glove_state_t shutting_down_state(state_data_t *state_data);

extern glove_state_t (*state_map[])(state_data_t *);

#endif
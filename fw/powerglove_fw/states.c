#include "states.h"

#include "nrf_gpio.h"
#include "nrf_delay.h"
#include "display.h"

glove_state_t (*state_map[])(state_data_t *) = {
  off_state,
  shutting_down_state
};

glove_state_t off_state(state_data_t *state_data) {
  state_data->d = 1;
  //display_write("0", DISPLAY_LINE_0);
  nrf_delay_ms(500);
  return SHUTTING_DOWN;
}

glove_state_t shutting_down_state(state_data_t *state_data) {
  state_data->d = 0;
  //display_write("1", DISPLAY_LINE_0);
  nrf_delay_ms(500);
  return OFF;
}

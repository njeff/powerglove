#include "millis.h"
#include "app_error.h"
#include "app_timer.h"
#include "nrf_drv_clock.h"

APP_TIMER_DEF(millis_timer_id);

// How to configure timer to run at 1024Hz?
// Current millis will overflow at around 8 minutes.
//#define APP_TIMER_CONFIG_RTC_FREQUENCY 31

static void lfclk_request(void)
{
    ret_code_t err_code = nrf_drv_clock_init();
    APP_ERROR_CHECK(err_code);
    nrf_drv_clock_lfclk_request(NULL);
}

static void expire_func(void *ptr)
{

}

void millisInit(void)
{
  lfclk_request();
  app_timer_init();
  ret_code_t error_code = app_timer_create(&millis_timer_id, APP_TIMER_MODE_SINGLE_SHOT, expire_func);
  APP_ERROR_CHECK(error_code);
  error_code = app_timer_start(millis_timer_id, 5, 0);
  APP_ERROR_CHECK(error_code);
}

uint32_t millis(void)
{
  return(app_timer_cnt_get() / 32.768);
}

uint32_t compareMillis(uint32_t previousMillis, uint32_t currentMillis)
{
  if(currentMillis < previousMillis) return(currentMillis + OVERFLOW + 1 - previousMillis);
  return(currentMillis - previousMillis);
}
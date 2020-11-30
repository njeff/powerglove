#ifndef MILLIS_H
#define MILLIS_H

#include <stdint.h>

#define OVERFLOW ((uint32_t)(0xFFFFFFFF/32.768))
#define APP_TIMER_PRESCALER

uint32_t millis(void);
void millisInit(void);
uint32_t compareMillis(uint32_t previousMillis, uint32_t currentMillis);

#endif
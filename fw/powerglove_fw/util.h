#ifndef _UTIL_H_
#define _UTIL_H_

#define SERVO_0 25
#define SERVO_1 24

#define BATTERY_PIN NRF_SAADC_INPUT_AIN1
#define BATTERY_CHANNEL 0
#define SERVO_FB_PIN NRF_SAADC_INPUT_AIN2
#define SERVO_FB_CHANNEL 1

void servoInit();
void setServoAngle(uint8_t servo_number, uint8_t v);
void adcInit();
float readBattery();
float readServoFB();

#endif
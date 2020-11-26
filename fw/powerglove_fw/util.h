#ifndef _UTIL_H_
#define _UTIL_H_

#define SERVO_0 25
#define SERVO_1 24

#define BATTERY_PIN NRF_SAADC_INPUT_AIN1
#define BATTERY_CHANNEL 0

void servoInit();
void setServoAngle(uint8_t servo_number, uint8_t v);
void batteryInit();
float readBattery();

#endif
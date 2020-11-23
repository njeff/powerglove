#ifndef _UTIL_H_
#define _UTIL_H_

#define SERVO_0 25
#define SERVO_1 24

void servoInit();
void setServoAngle(uint8_t servo_number, uint8_t v);

#endif
#ifndef PWM_SERVO_H
#define PWM_SERVO_H

#include "pico/stdlib.h"
#include "hardware/pwm.h"

void set_servo_angle(uint angle);

#endif // PWM_SERVO_H
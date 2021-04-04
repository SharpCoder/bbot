/*
 * Motors.h
 * ------------------------------
 * This module defines all motor commands which can be sent
 * to the circuit, and handles configuration of the shift register
 * accordingly.
 */

#ifndef __MOTORS_H_
#define __MOTORS_H_

#include "pinout.h"
#include "shift.h"

#define MAX_PHASE 3
#define MIN_PHASE 0

typedef enum { MotorLeft = 1, MotorRight = 2 } motor_t;

void step_forward(motor_t motor);
void step_backward(motor_t motor);

#endif

/*
 * Motors.h
 * ------------------------------
 * This module defines all motor commands which can be sent
 * to the circuit, and handles configuration of the shift register
 * accordingly.
 */

#ifndef __MOTORS_H_
#define __MOTORS_H_

typedef enum { MotorLeft = 1, MotorRight = 2 } motor_t;

void stepForward(motor_t motor);
void stepBackward(motor_t motor);

#endif

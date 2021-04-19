#ifndef __PINOUT_H_
#define __PINOUT_H_

#include <Arduino.h>

/*
 * ADXL335 ACCELEROMETER
 */
 #define  COMPASS_X_PIN A0
 #define  COMPASS_Y_PIN A1
 #define  COMPASS_Z_PIN A2

/*
 * SPARKFUN OPENLOG
 */
 #define  OPENLOG_TX  10
 #define  OPENLOG_RX  9

/* 
 *  SHIFT REGISTER
 *  These values represent the shift register pins
 *  which are directly connected to the arduino.
 */
#define SHIFT_REG_CLCK  2
#define SHIFT_REG_DATA  3
#define SHIFT_REG_LATCH 4
#define SHIFT_REG_CLEAR 5

/* 
  MOTORS
  Each motor is hooked up to the shift register. The value
  represents which pin index that particular phase (A-D) is
  configured against.
*/
#define MOTOR_1_A  0
#define MOTOR_1_B  1
#define MOTOR_1_C  3
#define MOTOR_1_D  2
#define MOTOR_2_A  4
#define MOTOR_2_B  5
#define MOTOR_2_C  6
#define MOTOR_2_D  7

#endif

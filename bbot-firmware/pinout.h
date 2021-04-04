#ifndef __PINOUT_H_
#define __PINOUT_H_

/* 
 *  SHIFT REGISTER
 *  These values represent the shift register pins
 *  which are directly connected to the arduino.
 */
#define SHIFT_REG_CLCK  2
#define SHIFT_REG_DATA  3
#define SHIFT_REG_LATCH 4

/* 
  MOTORS
  Each motor is hooked up to the shift register. The value
  represents which pin index that particular phase (A-D) is
  configured against.
*/
#define MOTOR_1_A  1
#define MOTOR_1_B  2
#define MOTOR_1_C  3
#define MOTOR_1_D  4
#define MOTOR_2_A  5
#define MOTOR_2_B  6
#define MOTOR_2_C  7
#define MOTOR_2_D  8

#endif

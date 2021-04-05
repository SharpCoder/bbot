/*
 * bbot-firmware.ino
 * ------------------------------
 * This is the entrypoint to bbot. A 2-wheel balancing robot
 * which uses an accelerometer to stabilize itself. All pins can be
 * configured using the pinout.h header file.
 * 
 * bbot-firmware uses the following components:
 * 74HC595N Shift Register
 * 2x bi-phasic 4-wire stepper motor
 * HMC5883L accelerometer
 * 
*/
#include "Arduino.h"
#include "pinout.h"
#include "shift.h"
#include "motors.h"

void setup() {  
  pinMode(SHIFT_REG_CLCK, OUTPUT);
  pinMode(SHIFT_REG_DATA, OUTPUT);
  pinMode(SHIFT_REG_LATCH, OUTPUT);
  pinMode(SHIFT_REG_CLEAR, OUTPUT);
}

void loop() {
  step_forward(MotorLeft);
  step_forward(MotorRight);
  
  delayMicroseconds(2000);
}

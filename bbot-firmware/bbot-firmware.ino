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
#include <Arduino.h>
#include <Wire.h>

#include "pinout.h"
#include "shift.h"
#include "motors.h"
#include "compass.h"
#include "theoretical_delay.h"

TheoreticalDelay jam = TheoreticalDelay();
Heading heading;

void setup() {  
  pinMode(SHIFT_REG_CLCK, OUTPUT);
  pinMode(SHIFT_REG_DATA, OUTPUT);
  pinMode(SHIFT_REG_LATCH, OUTPUT);
  pinMode(SHIFT_REG_CLEAR, OUTPUT);
  pinMode(A4, INPUT);
  pinMode(A5, OUTPUT);

  Serial.begin(9600);
  Wire.begin();
  init_compass();
}

void loop() {
  jam.defer(handle_motors, 2);
  jam.defer(handle_update_compass, 67);
  jam.process();
}

void handle_update_compass(void) {
  heading = read_compass();
}

void handle_motors(void) {
  step_forward(MotorLeft);
  step_forward(MotorRight);
}

/*
   bbot-firmware.ino
   ------------------------------
   This is the entrypoint to bbot. A 2-wheel balancing robot
   which uses an accelerometer to stabilize itself. All pins can be
   configured using the pinout.h header file.

   bbot-firmware uses the following components:
   74HC595N Shift Register
   2x bi-phasic 4-wire stepper motor
   HMC5883L accelerometer
*/
#include <Arduino.h>
#include <Wire.h>
#include "adxl335.h"
#include "logger.h"
#include "motors.h"
#include "pinout.h"
#include "shift.h"
#include "timer.h"

enum AIGravityState { 
  FALLING_FORWARD,
  FALLING_BACKWARD,
  STABLE,
  CRASHED,
};

VectorData compass_data;

long ms = 0;
void setup() {
  // Pilot light
  pinMode(13, OUTPUT);

  // Shift register pins
  pinMode(SHIFT_REG_CLCK, OUTPUT);
  pinMode(SHIFT_REG_DATA, OUTPUT);
  pinMode(SHIFT_REG_LATCH, OUTPUT);
  pinMode(SHIFT_REG_CLEAR, OUTPUT);

  // Serial used for debugging
  Serial.begin(9600);

  // Wire used for i2c
  Wire.begin();

  // Initalize peripherals and subsystems
  logger_init();
  init_timer_subsystem();
  
  // Turn on pilot light
  digitalWrite(13, HIGH);
}

void loop() {
  // The motors can only actuate once every 2ms
  // so we might as well hold off computation
  // until they are ready to go.
  defer(ai_main, 2);

  // The accelerometer requires a 67ms delay
  // between readings.
  defer(update_compass, 30);

  // This will handle orchestrating all currently
  // open threads which need processing.
  process_timers();
}

/*
    Function: update_compass
    ---------------------------------------------------
    This method simply calls the compass_read function
    every 67ms which is the minimum amount of time
    you should wait for the 15Hz configuration.
*/
void update_compass(void) {
  compass_data = compass_read();
  
  // Stream telemetry to the SDCard
  logger_log(
    compass_data.x,
    compass_data.y,
    compass_data.z
  );
}

/*
    Function: ai_compute_gravity_state
    ---------------------------------------------------
    This method will take some vector data and return
    the current state of the robot relative to gravity.
    I.E. are we falling, if so, which direction.
*/
AIGravityState ai_compute_gravity_state(VectorData data) {
  return FALLING_FORWARD;
}

/*
    Function: ai_main
    ---------------------------------------------------
    This method is the primary logic for the algorithm.

    General theory: move in the direction we are
    falling. To achieve this, we must be constantly
    polling the accelerometer to determine direction
    we are falling. With these readings, we will decide
    which direction each respective motor needs to be
    moving.
*/
void ai_main() {

  AIGravityState gravity_state = ai_compute_gravity_state(compass_data);

  switch (gravity_state) {
    case FALLING_FORWARD: {
      step_forward(MotorLeft);
      step_forward(MotorRight);
    }
    break;
    case FALLING_BACKWARD: {
      step_backward(MotorLeft);
      step_backward(MotorRight);
    }
    break;
    case STABLE: {
      // Do nothing
    }
    break;
    case CRASHED: {
      // Do nothing
    }break;
  }
}

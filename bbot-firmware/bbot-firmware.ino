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
#include "adxl335.h"
#include "motors.h"
#include "pinout.h"
#include "shift.h"
#include "timer.h"

#define GRAVITY_NEUTRAL 316.0
#define GRAVITY_THRESHOLD 3.0
#define GRAVITY_CRASHED 60.0
#define GRAVITY_AVG_COUNT 3.0

enum AIGravityState { 
  FALLING_FORWARD,
  FALLING_BACKWARD,
  STABLE,
  CRASHED,
};

VectorData compass_data;
float avg_rotation_base = 0.0;
float avg_rotation_count = 0.0;

boolean crashed = false;
void setup() {
  // Indicator light representing total system shutdown
//  pinMode(LED_BUILTIN, OUTPUT);
//  digitalWrite(LED_BUILTIN, LOW);

  // Accelerometer
  pinMode(COMPASS_X_PIN, INPUT);
  pinMode(COMPASS_Y_PIN, INPUT);
  pinMode(COMPASS_Z_PIN, INPUT);

  // Shift register pins
  pinMode(SHIFT_REG_CLCK, OUTPUT);
  pinMode(SHIFT_REG_DATA, OUTPUT);
  pinMode(SHIFT_REG_LATCH, OUTPUT);
  pinMode(SHIFT_REG_CLEAR, OUTPUT);

  // Serial used for debugging
  Serial.begin(115200);

  // Spend 2 seconds calculating the average accelerometer reading.
  // This does two things.
  // First - It is a built-in wait timer for the application start.
  // Second - It allows us to calculate a rolling average from here on out.
  for (int i = GRAVITY_AVG_COUNT; i > 0; i--) {
    // Update the compass readings
    update_compass();
    delay(2000 / GRAVITY_AVG_COUNT);
  }

//  // Initalize peripherals and subsystems
  timer_init();
}

void loop() {
  // Robot will remain idle after a crash
  if (crashed) {
    Serial.println("CRASHED");
    return;
  }
//  digitalWrite(LED_BUILTIN, HIGH);
//  delay(1000);
//  digitalWrite(LED_BUILTIN, LOW);
//  delay(1000);
  defer(ai_main, 20);
  defer(update_compass, 3);

  // This will handle orchestrating all currently
  // open threads which need processing.
  process_timers();
//  step_backward(MotorRight);
//  step_forward(MotorLeft);

//  update_compass();
//  Serial.println(get_rotation(compass_data));

//  delay(14);
}

/*
    Function: update_compass
    ---------------------------------------------------
    This method simply calls the compass_read function
    and saves the current data in a global variable.
*/
void update_compass(void) {
  compass_data = compass_read();

  // While we're at it, update the
  // rolling average rotation value.
  float rotation = get_rotation(compass_data);
  if (avg_rotation_count < GRAVITY_AVG_COUNT) {
    avg_rotation_base += rotation;
    avg_rotation_count++;
  } else {
    avg_rotation_base = avg_rotation_base - (avg_rotation_base / GRAVITY_AVG_COUNT) + rotation;
  }
}

/*
    Function: get_rotation
    ---------------------------------------------------
    A convenience method which returns the axis
    representing rotation based on the sensor
    orientation. Since it's mounted in a specific
    and non-standard axis.
*/
float get_rotation(VectorData data) {
  return data.y;
}

/*
    Function: ai_compute_gravity_state
    ---------------------------------------------------
    This method will take some vector data and return
    the current state of the robot relative to gravity.
    I.E. are we falling, if so, which direction.
*/
AIGravityState ai_compute_gravity_state(VectorData data) {
  float rotation = get_rotation(data);
  float avg_rotation = avg_rotation_base / avg_rotation_count;
  float dist_to_neutral = abs(GRAVITY_NEUTRAL - rotation);
  float avg_dist_to_neutral = abs(GRAVITY_NEUTRAL - avg_rotation);
  
//  Serial.print("rotation: ");
//  Serial.println(avg_rotation);
//  Serial.print("dist_to_neutral: ");
//  Serial.println(avg_dist_to_neutral);
  
  if (avg_dist_to_neutral > GRAVITY_CRASHED) {
    // We are in a very bad state
    return CRASHED;
  } else if (avg_dist_to_neutral > GRAVITY_THRESHOLD) {
    // We are falling
    if (avg_rotation > GRAVITY_NEUTRAL) {
      return FALLING_FORWARD;
    } else {
      return FALLING_BACKWARD;
    }
  } else {
    // We are in a neutral state
    return STABLE;
  }
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
      crashed = true;
    }
    break;
  }
}

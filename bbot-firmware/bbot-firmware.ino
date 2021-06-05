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

#define MOTOR_LOOP_DELAY 9
#define GRAVITY_NEUTRAL 308.0
#define GRAVITY_THRESHOLD 3.0
#define GRAVITY_CRASHED 65.0
#define GRAVITY_AVG_COUNT 9.0

enum AIGravityState { 
  FALLING_FORWARD,
  FALLING_BACKWARD,
  STABLE,
  CRASHED,
};

VectorData compass_data;
AIGravityState real_gravity_state = STABLE;
AIGravityState active_gravity_state = STABLE;

float avg_rotation_base = 0.0;
float avg_rotation_count = 0.0;
long motor_loop_target_ms = 0;

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
    return;
  }
  
  defer(ai_main, 28);
  defer(update_compass, 4);

  // This will handle orchestrating all currently
  // open threads which need processing.
  process_timers();
  process_motor_loop();
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
  
//  Serial.print("<");
//  Serial.print("[");
//  Serial.print(millis());
//  Serial.print(",");
//  Serial.print(avg_rotation);
//  Serial.print(",");
//  Serial.print(rotation);
//  Serial.print(",");
//  Serial.print(data.x);
//  Serial.print(",");
//  Serial.print(data.y);
//  Serial.print(",");
//  Serial.print(data.z);
//  Serial.println("],");
//  
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
  real_gravity_state = ai_compute_gravity_state(compass_data);
}

void process_motor_loop() {
  long now = millis();
  if (real_gravity_state != active_gravity_state || now > motor_loop_target_ms) {
    switch (active_gravity_state) {
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
        if (crashed != true) {
          Serial.println("CRASHED");
        }
        crashed = true;
      }
      break;
    }

    motor_loop_target_ms = millis() + MOTOR_LOOP_DELAY;
    active_gravity_state = real_gravity_state;
  }
}

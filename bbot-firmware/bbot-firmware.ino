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
#include "compass.h"
#include "debug.h"
#include "motors.h"
#include "pinout.h"
#include "shift.h"
#include "timer.h"

#define CALIBRATION_MODE    true
#define ROTATION_BASELINE   70
#define ROTATION_THRESHOLD  3

VectorData compass_data;

// Theta (angle) of rotation
byte theta_idx = 0;
float theta_readings[3] = {
  ROTATION_BASELINE,
  ROTATION_BASELINE,
  ROTATION_BASELINE
};

long ms = 0;

void setup() {
  // Pilot light
  pinMode(13, OUTPUT);

  // Shift register pins
  pinMode(SHIFT_REG_CLCK, OUTPUT);
  pinMode(SHIFT_REG_DATA, OUTPUT);
  pinMode(SHIFT_REG_LATCH, OUTPUT);
  pinMode(SHIFT_REG_CLEAR, OUTPUT);

  // I2c pins
  pinMode(A4, INPUT);
  pinMode(A5, OUTPUT);

  // Serial used for debugging
  Serial.begin(9600);

  // Wire used for i2c
  Wire.begin();

  // Initalize peripherals and subsystems
  compass_init();
  init_timer_subsystem();

  // Calibrate and such
//  compass_self_test();

  // Turn on pilot light
  digitalWrite(13, HIGH);
}

void loop() {
  if (CALIBRATION_MODE) {
    calibrate_loop();
  } else {
    // The motors can only actuate once every 2ms
    // so we might as well hold off computation
    // until they are ready to go.
    defer(ai_main, 2);
  
    // The accelerometer requires a 67ms delay
    // between readings.
    defer(update_compass, 67);
  
    // This will handle orchestrating all currently
    // open threads which need processing.
    process_timers();
  }
}

/*
    Function: update_compass
    ---------------------------------------------------
    This method
*/
int16_t compass_max[3] = { -4096, -4096, -4096};
int16_t compass_min[3] = {4096, 4096, 4096};

void update_compass(void) {
  compass_data = compass_read();

  compass_data.x += 254;
  compass_data.y += 1117;
  compass_data.z += 5;
  compass_data.x /= 256;
  compass_data.y /= 666;
  compass_data.z /= 514;
  compass_data.z -= .5;

  compass_max[0] = max(compass_max[0], compass_data.x);
  compass_max[1] = max(compass_max[1], compass_data.y);
  compass_max[2] = max(compass_max[2], compass_data.z);
  compass_min[0] = min(compass_min[0], compass_data.x);
  compass_min[1] = min(compass_min[1], compass_data.y);
  compass_min[2] = min(compass_min[2], compass_data.z);

  //  // Update the rotation angle readings
  //  theta_readings[theta_idx] = compass_data.z;
  //  theta_idx++;
  //  if (theta_idx == 3) {
  //    theta_idx = 0;
  //  }

  if (false) {
    Serial.print("Max <");
    Serial.print(compass_max[0]);
    Serial.print(", ");
    Serial.print(compass_max[1]);
    Serial.print(", ");
    Serial.print(compass_max[2]);
    Serial.print(">   Min <");
    Serial.print(compass_min[0]);
    Serial.print(", ");
    Serial.print(compass_min[1]);
    Serial.print(", ");
    Serial.print(compass_min[2]);
    Serial.println(">");
  }


  if (true) {
    Serial.print("<");
    Serial.print(compass_data.x);
    Serial.print(", ");
    Serial.print(compass_data.y);
    Serial.print(", ");
    Serial.print(compass_data.z);
    Serial.print(">  ");

    Serial.print("Tilt: ");
    Serial.println(asin(compass_data.z));

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
  //Question: does heading even matter?
  float theta = (theta_readings[0] + theta_readings[1] + theta_readings[2]) / 3.0;
  bool falling = theta > (ROTATION_BASELINE + ROTATION_THRESHOLD) ||
                 theta < (ROTATION_BASELINE - ROTATION_THRESHOLD);

  step_forward(MotorLeft);

  falling = true;
  // If we are falling, move in the direction
  if (falling) {
    step_forward(MotorLeft);
    step_forward(MotorRight);
  } else if (falling && theta < ROTATION_BASELINE) {
    step_backward(MotorLeft);
    step_backward(MotorRight);
  }
}

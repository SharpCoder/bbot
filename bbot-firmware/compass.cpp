#include "compass.h"

// COMPASS_MULTIPLIERS are calibrated per sensor and require an rigorous
// test environment. See README.md for more information.
uint16_t COMPASS_MULTIPLIERS[360] = { 
  1548, 1548, 1667, 1667, 2000, 1667, 2000, 2000, 2000, 2000, 2000, 1833, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 3333, 2500, 3333, 3333, 3333, 3333, 3333, 3333, 3333, 3333, 5000, 5000, 5000, 5000, 5000, 5000, 5000, 5000, 5000, 5000, 5000, 5000, 5000, 5000, 10000, 5000, 7500, 10000, 5000, 5000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 5000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 5000, 10000, 5000, 5000, 7500, 5000, 5000, 10000, 5000, 5000, 5000, 5000, 5000, 5000, 5000, 4167, 4167, 5000, 4167, 4167, 4167, 4167, 3333, 3333, 3333, 3333, 3333, 2500, 2500, 3333, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2000, 2000, 2000, 2000, 2500, 2000, 2000, 1833, 2000, 1667, 1667, 2000, 1667, 1667, 1667, 1667, 1667, 1667, 1429, 1429, 1429, 1429, 1250, 1250, 1429, 1429, 1429, 1429, 1250, 1250, 1250, 1250, 1111, 1111, 1111, 1111, 1111, 1111, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 909, 909, 909, 909, 909, 909, 909, 909, 909, 833, 801, 769, 769, 801, 769, 769, 769, 714, 769, 714, 714, 769, 769, 714, 714, 714, 714, 690, 667, 690, 690, 667, 667, 667, 653, 653, 667, 646, 646, 625, 625, 625, 625, 625, 607, 588, 607, 588, 613, 588, 588, 607, 588, 588, 588, 572, 588, 588, 588, 556, 556, 556, 556, 556, 556, 504, 503, 507, 500, 509, 519, 501, 512, 513, 526, 536, 541, 541, 541, 548, 536, 526, 541, 541, 541, 541, 526, 526, 541, 526, 556, 556, 541, 541, 556, 550, 556, 556, 551, 556, 556, 541, 541, 556, 556, 566, 588, 556, 577, 556, 556, 556, 588, 588, 588, 588, 594, 578, 560, 588, 625, 625, 625, 625, 625, 625, 625, 667, 667, 667, 667, 714, 714, 714, 714, 714, 714, 714, 769, 769, 769, 714, 769, 833, 833, 833, 801, 833, 833, 833, 833, 909, 871, 871, 909, 909, 909, 939, 955, 955, 1000, 1000, 1000, 1000, 1056, 1111, 1111, 1181, 1250, 1111, 1250, 1250, 1250, 1339, 1429, 1429, 1429, 1667, 1429
};

// Given a particular gain (0 - 7) return the value which, if configured, will yield that gain setting
int COMPASS_GAINS[8] = {0x00, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0, 0xE0};

// Given a particular gain, define the lower and upper limit of what constitutes a
// a "positive self test" value.
int GAIN_LIMITS[8][2] = {
  {853, 2019}, // Gain 0
  {679, 1607}, // Gain 1
  {510, 1208}, // Gain 2
  {411, 973},  // Gain 3
  {274, 648},  // Gain 4
  {243, 575},  // Gain 5
  {206, 487},  // Gain 6
  {143, 339}   // Gain 7
};

// Presently unused.
float GAIN_SCALES[8] = {
  0.73,
  0.92,
  1.22,
  1.52,
  2.27,
  2.56,
  3.03,
  4.35
};

// Current gain configuration for the sensor.
int gain = 5;

/* 
 *  Function: _compute_heading
 *  ---------------------------------------------------
 *  This method takes x and z dimensions and computes
 *  the directional heading using trig.
 */
float _compute_heading(float x, float z) {
  // Apply the offsets to normalize the values based
  // on the plane it is mounted on and then compute the heading
  x = x + COMPASS_X_OFFSET;
  z = z + COMPASS_Z_OFFSET;

  // Compute the angle in degrees
  float heading = atan2(z, x) * (180/M_PI);

  // Constrain the value
  if (heading < 0) {
    heading = 360 - abs(heading);
  }

  return (float)((int)heading % 360);
}

/* 
 *  Function: _assert_gain_value
 *  ---------------------------------------------------
 *  This method will take a character representing a
 *  dimension, and a value. And then check whether the
 *  value is within the min/max threshold of currently
 *  configured gain. If not, some debug info is output
 *  and this method returns false.
 *  
 *  Returns true if value is within threshold.
 */
bool _assert_gain_value(char dimension, int val) {
  int min_val = GAIN_LIMITS[gain][0];
  int max_val = GAIN_LIMITS[gain][1];
  if (val < min_val || val > max_val) {
    Serial.print("Gain ");
    Serial.print(gain);
    Serial.print(" failed axis ");
    Serial.print(dimension);
    Serial.print(" with value ");
    Serial.print(val);
    Serial.print("  - threshold <");
    Serial.print(min_val);
    Serial.print(", ");
    Serial.print(max_val);
    Serial.println(">");
    return false;
  } else {
    return true;
  }
}

/* 
 *  Function: init_compass
 *  ---------------------------------------------------
 *  This method will initialize the compass according
 *  to the datasheet by requesting the device enter
 *  single-value mode.
 */
void compass_init(void) {
  // Initialize continuous collection mode
  i2c_write_byte(COMPASS_DEVICE_ID, 0x00, 0x70);
  i2c_write_byte(COMPASS_DEVICE_ID, 0x01, COMPASS_GAINS[gain]);
  i2c_write_byte(COMPASS_DEVICE_ID, 0x02, 0x00);
  
  // Then delay 6ms according to datasheet
  delay(6);
}

/* 
 *  Function: self_test
 *  ---------------------------------------------------
 *  This method will enter the compass module into
 *  self-test mode which uses magic to create magnetic
 *  fields, allowing the sensor to derive
 */
void compass_self_test(void) {
  VectorData heading;

  // Enter self-test mode
  i2c_write_byte((uint8_t)COMPASS_DEVICE_ID, (uint8_t)0x00, (uint8_t)0x71);
  delay(6);

  // Test each gain
  for (gain = 7; gain >= 0; gain--) {
    bool exit_loop = false;
    
    for (int samples = 0; samples < 3; samples++) {
      // Take some readings, save the last one
      heading = compass_read();
      delay(67);
      heading = compass_read();
      delay(67);
      heading = compass_read();
      delay(67);
  
      // Check that values are within tolerances
      bool success = _assert_gain_value('X', heading.x)
        && _assert_gain_value('Y', heading.y)
        && _assert_gain_value('Z', heading.z);
  
      if (success) {
        exit_loop = true;
        break;
      }
    }

    if (exit_loop) {
      break;
    }
  }

  if (gain < 0) {
    // ERROR
    Serial.println("ERROR: compass failed self-test");
    while(1) { }
  } else {
    Serial.print("Compass self-test succeeded! Gain configured at ");
    Serial.println(gain);
  }

  // Exit self-test mode
  i2c_write_byte(COMPASS_DEVICE_ID, 0x00, 0x70);
  delay(6);
  
  compass_init();
}

/* 
 *  Function: compass_read_raw
 *  ---------------------------------------------------
 *  This method will initiate an i2c_read_bytes
 *  operation against the compass peripheral and return
 *  the normalized X,Y,Z heading values.
 */
VectorData compass_read_raw(void) {
  // Read the bytes from device
  byte data[6];
  i2c_read_bytes(COMPASS_DEVICE_ID, 0x03, 6, data);  

  // Convert the values into their 16bit representations.
  // Apparently this'll just "work" for conversion into float datatype.
  int16_t x = ((int16_t)data[0] << 8) | (int16_t)data[1];
  int16_t z = ((int16_t)data[2] << 8) | (int16_t)data[3];
  int16_t y = ((int16_t)data[4] << 8) | (int16_t)data[5];

  // Finally, convert the integer into floats and return the resulting datastructure
  return VectorData {
    x: (float)x,
    y: (float)y, 
    z: (float)z,
    heading: _compute_heading(x, z),
  };
}

/* 
 *  Function: compass_read
 *  ---------------------------------------------------
 *  This method will initiate an i2c_read_bytes
 *  operation against the compass peripheral and then
 *  adjust the raw values based on calibration values
 *  to yield corrected readings.
 */
VectorData compass_read(void) {
  VectorData data = compass_read_raw();
  data.x += COMPASS_X_OFFSET;
  data.y += COMPASS_Y_OFFSET;
  data.z += COMPASS_Z_OFFSET;
  
  // Next, use the heading angle to discover the encoded 
  // calibration multiplier.
  float calibration_multiplier = COMPASS_MULTIPLIERS[(int)data.heading];

  // Now apply the multiplier
  data.y *= (calibration_multiplier / 10000);

  // Boundary detection
  if (data.y > 5) {
    data.y /= 10.0;
  }

  // Sign flip based on heading
  if (data.heading >= 180) {
    data.y *= -1;
  }

  return data;    
}

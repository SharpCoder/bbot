#include "adxl335.h"

/*
    Function: compass_read
    ---------------------------------------------------
    This method will statelessly query the compass
    peripheral and return all positional information
    as raw floating point values.

    Heading will be computed using atan2.
*/
VectorData compass_read() {
  float x = analogRead(COMPASS_X_PIN);
  float y = analogRead(COMPASS_Y_PIN);
  float z = analogRead(COMPASS_Z_PIN);
  float heading = atan2(y,x);

  return {
    x,
    y,
    z,
    heading,
  };
}

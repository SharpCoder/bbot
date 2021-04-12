/*
 * compass.h
 * ------------------------------
 * This module defines all accelerometer commands
 */
#ifndef __ACCELEROMETER_H_
#define __ACCELEROMETER_H_

#include <Arduino.h>
#include "i2c.h"

#define COMPASS_DEVICE_ID (uint8_t)0x1E
#define COMPASS_X_OFFSET  25
#define COMPASS_Y_OFFSET  252
#define COMPASS_Z_OFFSET  16

struct VectorData {
  float x;
  float y;
  float z;
  float heading;
};

void compass_init(void);
void compass_self_test(void);
VectorData compass_read_raw(void);
VectorData compass_read(void);

#endif

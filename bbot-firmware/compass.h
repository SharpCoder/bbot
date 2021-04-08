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

struct Heading {
  float x;
  float y;
  float z;
};

void init_compass(void);
Heading read_compass(void);

#endif

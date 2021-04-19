/*
 * adxl335.h
 * ------------------------------
 * This module is used to control
 * the accelerometer chip.
 */
 
#ifndef __ADXL335__H_
#define __ADXL335__H_

#include <Arduino.h>
#include "pinout.h"

typedef struct {
  float x;
  float y;
  float z;
  float heading;
} VectorData;

VectorData compass_read();

#endif

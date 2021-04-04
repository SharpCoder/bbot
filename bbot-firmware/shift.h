/*
 * Shift.h
 * ------------------------------
 * This module defines all the logic for interacting with
 * the shift register.
*/

#ifndef __SHIFT_H_
#define __SHIFT_H_

#include <Arduino.h>
#include "pinout.h"

void update_shift_registers(int values[8]);

#endif

#include "shift.h"

/* 
 *  Function: update_shift_registers
 *  ---------------------------------------------------
 *  This method takes an array of values 0 - 7 and
 *  converts them into a byte which is then
 *  transmitted to the shift register using the 
 *  built-in shiftOut operator.
 */
void update_shift_registers(int values[8]) {
  digitalWrite(SHIFT_REG_CLCK, HIGH);
  digitalWrite(SHIFT_REG_LATCH, LOW);

  // Compute final value by iterating over each index in the array
  // and using its base value, then shifting over "index" qty of bits
  // and bitwise or'ing the result.
  int value_to_write = 0x0;
  for (int value_index = 0; value_index < 8; value_index++) {
    value_to_write = value_to_write | (values[value_index] << value_index);
  }

  // TODO: hardwire this to HIGH
  digitalWrite(SHIFT_REG_CLEAR, HIGH);
  
  // Begin writing
  shiftOut(SHIFT_REG_DATA, SHIFT_REG_CLCK, MSBFIRST, value_to_write);

  // Signal completion of output
  digitalWrite(SHIFT_REG_LATCH, LOW);
  digitalWrite(SHIFT_REG_LATCH, HIGH);
}

#include "shift.h"

void update_shift_registers(int values[8]) {
  // CLOCK and LATCH must be high before writing
  digitalWrite(SHIFT_REG_CLCK, HIGH);
  digitalWrite(SHIFT_REG_LATCH, HIGH);

  // Compute final value by iterating over each index in the array
  // and using its base value, then shifting over "index" qty of bits
  // and bitwise or'ing the result.
  int value_to_write = 0x0;
  for (int value_index = 0; value_index < 8; value_index++) {
    value_to_write = value_to_write | (values[value_index] << value_index);
  }
  
  // Begin writing
  shiftOut(SHIFT_REG_DATA, SHIFT_REG_CLCK, LSBFIRST, value_to_write);

  // Signal completion of output
  digitalWrite(SHIFT_REG_LATCH, LOW);
}

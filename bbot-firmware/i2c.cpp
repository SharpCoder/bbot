#include "i2c.h"

/* 
 *  Function: i2c_write_command
 *  ---------------------------------------------------
 *  This method takes an i2c device_id and a single byte command
 *  and transmits it.
 *  
 *  This function returns an i2c_status_t object defining the success state of
 *  the transmission operation.
  */
i2c_status_t i2c_write_command(uint8_t device_id, uint8_t command) {
  Wire.beginTransmission(device_id);
  Wire.write(byte(command));
  return (i2c_status_t)Wire.endTransmission();
}

/* 
 *  Function: i2c_write_byte
 *  ---------------------------------------------------
 *  This method takes an i2c device_id, a destination register, and a data byte.
 *  It will then transmit both bytes - register and data. For certain peripherals
 *  you must specify the receiving register address and the value to write to it.
 *  
 *  This function returns an i2c_status_t object defining the success state of
 *  the transmission operation.
  */
i2c_status_t i2c_write_byte(uint8_t device_id, uint8_t reg_addr, uint8_t data) {
  Wire.beginTransmission(device_id);
  Wire.write(byte(reg_addr));
  Wire.write(byte(data));
  return (i2c_status_t)Wire.endTransmission();
}

/* 
 *  Function: i2c_read_byte
 *  ---------------------------------------------------
 *  This method takes a device_id and a register address and will
 *  update the i2c device so it points to the register, then
 *  request a single byte of data and return the value.
  */
byte i2c_read_byte(uint8_t device_id, uint8_t reg_addr) {
  Wire.beginTransmission(device_id);
  Wire.write(byte(reg_addr));
  Wire.endTransmission(false);
  Wire.requestFrom(device_id, 1);
  byte result = 0x00;
  while (Wire.available()) {
    result = Wire.read();
  }
  return result;
}

/* 
 *  Function: i2c_read_bytes
 *  ---------------------------------------------------
 *  This method takes a device_id, register address,
 *  quantity of bytes, and destination buffer. It
 *  will then point the i2c device to the register
 *  and request a number of bytes from the device equal
 *  to qty_of_bytes. The result is stored in the
 *  destination buffer.
 *  
 *  The return value of this function is the i2c_status_t
 *  object representing the status of the register 
 *  transmission operation.
  */
i2c_status_t i2c_read_bytes(uint8_t device_id, uint8_t reg_addr, uint8_t qty_of_bytes, uint8_t *destination) {
  Wire.beginTransmission(device_id);
  Wire.write(byte(reg_addr));
  i2c_status_t transmission_result = (i2c_status_t)Wire.endTransmission(false);
  Wire.requestFrom(device_id, qty_of_bytes);
  uint8_t index = 0;
  while (Wire.available()) {
    *(destination + index) = Wire.read();
    index += 1;
  }
  return transmission_result;
}

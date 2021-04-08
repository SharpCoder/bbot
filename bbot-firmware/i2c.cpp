#include "i2c.h"


i2c_status_t i2c_write_command(uint8_t device_id, uint8_t command) {
  Wire.beginTransmission(device_id);
  Wire.write(byte(command));
  return (i2c_status_t)Wire.endTransmission();
}

i2c_status_t i2c_write_byte(uint8_t device_id, uint8_t reg_addr, uint8_t data) {
  Wire.beginTransmission(device_id);
  Wire.write(byte(reg_addr));
  Wire.write(byte(data));
  return (i2c_status_t)Wire.endTransmission();
}

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

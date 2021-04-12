/*
 * i2c.h
 * ------------------------------
 * This module defines convenience methods surrounding
 * i2c communication.
 */
#ifndef __I2C_H_
#define __I2C_H_

#include <Arduino.h>
#include <Wire.h>

typedef enum i2c_status_t {
  SUCCESS = 0,
  ERROR_DATA_TOO_LONG = 1,
  ERROR_NACK_ON_ADDR_TX = 2,
  ERROR_NACK_ON_DATA_TX = 3,
  ERROR_OTHER = 4
} i2c_status_t;

i2c_status_t i2c_write_command(uint8_t device_id, uint8_t command);
i2c_status_t i2c_write_byte(uint8_t device_id, uint8_t reg_addr, uint8_t data);
byte i2c_read_byte(uint8_t device_id, uint8_t reg_addr);
i2c_status_t i2c_read_bytes(uint8_t device_id, uint8_t reg_addr, uint8_t qty_of_bytes, uint8_t *destination);

#endif

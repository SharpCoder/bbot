#include "compass.h"


/* 
 *  Function: init_compass
 *  ---------------------------------------------------
 *  This method will initialize the compass according
 *  to the datasheet by requesting the device enter
 *  single-value mode.
 */
void init_compass(void) {
  // Initialize single-value mode
  i2c_write_byte((uint8_t)COMPASS_DEVICE_ID, (uint8_t)0x00, (uint8_t)0x70);
  i2c_write_byte(COMPASS_DEVICE_ID, 0x00, 0xA0);
  
  // Then delay 6ms according to datasheet
  delay(6);
}

/* 
 *  Function: read_compass
 *  ---------------------------------------------------
 *  This method will initiate an i2c_read_bytes
 *  operation against the compass peripheral and return
 *  the normalized X,Y,Z heading values.
 */
Heading read_compass(void) {
  // Signal command to initiate a single read event
  i2c_write_byte(COMPASS_DEVICE_ID, 0x02, 0x01);

  // TODO: delay(6)
  
  // Read the bytes from device
  byte data[6];
  i2c_read_bytes(COMPASS_DEVICE_ID, 0x03, 6, data);  

  // Convert the values into their 16bit representations.
  // Apparently this'll just "work" for conversion into float datatype.
  int x = ((uint16_t)data[0] << 8) | (uint16_t)data[1];
  int z = ((uint16_t)data[2] << 8) | (uint16_t)data[3];
  int y = ((uint16_t)data[4] << 8) | (uint16_t)data[5];

  // Finally, convert the integer into floats and return the resulting datastructure
  return Heading {
    x: (float)x,
    y: (float)y, 
    z: (float)z
  };
}

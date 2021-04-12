#include "debug.h"

void collect_data() {
  VectorData heading = compass_read_raw();
    
  Serial.print("[");
  Serial.print(heading.x);
  Serial.print(",");
  Serial.print(heading.y);
  Serial.print(",");
  Serial.print(heading.z);
  Serial.print(",");
  Serial.print(millis());
  Serial.print("], ");
}


void _display_rotation() {
  VectorData vector = compass_read();
  
  bool show = vector.y < 0.5 || vector.y > 2.0;
  if (show) {
    Serial.print("<");
    Serial.print(vector.x);
    Serial.print(", ");
    Serial.print(vector.y);
    Serial.print(", ");
    Serial.print(vector.z);
    Serial.print(", ");
    Serial.print(vector.heading);
    Serial.print(">   ");
    Serial.println(vector.y);
  }
}


void debug_loop() {
//  collect_data();
  _display_rotation();
  delay(67);
}

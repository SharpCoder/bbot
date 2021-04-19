#include "logger.h"

SoftwareSerial log_serial(OPENLOG_RX, OPENLOG_TX);

/*
    Function: logger_init
    ---------------------------------------------------
    This method establishes a connection with the
    OpenLog breakout board through SoftwareSerial
    using baud rate 9600 (per recommendation) and
    then creates a new file and opens a streaming
    connection with it.
*/
void logger_init() {
  log_serial.begin(9600);
  log_serial.print("new LOG000.txt\r");
}

/*
    Function: logger_log
    ---------------------------------------------------
    This method will take telemetry from the compass
    module and write them into the currently open log
    file which is unique per session. The format of the
    file is simply x,y,z per line.
*/
void logger_log(float x, float y, float z) {
  log_serial.print(x);
  log_serial.print(",");
  log_serial.print(y);
  log_serial.print(",");
  log_serial.print(z);
  log_serial.print("\r");
}

/*
 * logger.h
 * ------------------------------
 * This peripheral communicates
 * with the SparkFun OpenLog
 * breakout board using
 * SoftwareSerial in order to
 * stream telemetry from the 
 * compass module to an SDCard
 * for offline viewing to help
 * with iterating over the
 * algorithm.
 */
 
#ifndef __LOGGER_H_
#define __LOGGER_H_

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "pinout.h"

void logger_init();
void logger_log(float x, float y, float z);

#endif

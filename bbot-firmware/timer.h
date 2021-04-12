/*
 * theoretical_delay.h
 * ------------------------------
 * This module is responsible for managing a non-blocking delay
 * mechanism which critical code-paths can use to effectively block
 * without interrupting other peripherals.
 */

#ifndef _TIMER_H_
#define _TIMER_H_

#include <Arduino.h>

#define MAX_TIMERS  10

typedef void (*func)();
typedef struct {
  func method;
  long unsigned int duration;
  long unsigned int target_ms;
  bool serviced;
} timer_t;

void init_timer_subsystem(void);
void process_timers(void);
void defer(func fn, long unsigned int ms);

#endif

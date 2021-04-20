/*
 * timer.h
 * ------------------------------
 * This module is responsible for managing a non-blocking delay
 * mechanism which critical code-paths can use to effectively block
 * without interrupting other peripherals.
 */

#ifndef __TIMER_H_
#define __TIMER_H_

#include <Arduino.h>

#define MAX_TIMERS  10

typedef void (*func)();
typedef struct {
  func method;
  long unsigned int duration;
  long unsigned int target_ms;
  bool serviced;
} delay_timer_t;

void timer_init(void);
void process_timers(void);
void defer(func fn, long unsigned int ms);

#endif

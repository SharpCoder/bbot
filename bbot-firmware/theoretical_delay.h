/*
 * theoretical_delay.h
 * ------------------------------
 * This module is responsible for managing a non-blocking delay
 * mechanism which critical code-paths can use to effectively block
 * without interrupting other peripherals.
 */

#ifndef __THEORETICAL_DELAY_H_
#define __THEORETICAL_DELAY_H_

#define MAX_TIMERS  10

typedef void (*functiontype)();

#include <Arduino.h>


class TheoreticalDelay {
  private:
    byte timer_index = 0;
    bool processed[MAX_TIMERS];
    long timers[MAX_TIMERS];
    functiontype functions[MAX_TIMERS];
    int get_next_timer();

  public:
    TheoreticalDelay();
    void process(void);
    void defer(functiontype fn, long ms);
};

#endif

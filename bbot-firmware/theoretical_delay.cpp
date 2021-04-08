#include "theoretical_delay.h"

TheoreticalDelay::TheoreticalDelay(void) {
  for (int i = 0; i < MAX_TIMERS; i++) {
    this->processed[i] = true;
  }
}

void noop(void) { }

void TheoreticalDelay::process(void) {
  for (int i = 0; i < MAX_TIMERS; i++) {
    if (this->processed[i] == false && millis() > this->timers[i]) {
      functiontype method = this->functions[i];
      method();
      this->processed[i] = true;
      this->functions[i] = noop;
    }
  }
}

int TheoreticalDelay::get_next_timer(void) {
  for (int i = 0; i < MAX_TIMERS; i++) {
    if (this->processed[i] == true) {
      return i;
    }
  }
  
  // ERROR CONDITION
  return 0;
}

void TheoreticalDelay::defer(functiontype fn, long ms) {
  // Check if this function already exists
  for (int i = 0; i < MAX_TIMERS; i++) {
    if (this->functions[i] == fn) {
      return;
    }
  }
  
  // Enqueue the function call
  int timer_id = this->get_next_timer();
  this->timers[timer_id] = millis() + ms;
  this->processed[timer_id] = false;
  this->functions[timer_id] = fn;
}

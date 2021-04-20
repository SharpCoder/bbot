#include "timer.h"

char timer_id = 0;
delay_timer_t timers[MAX_TIMERS];

/* 
 *  Function: noop
 *  ---------------------------------------------------
 *  This method does absolutely nothing.
 */
void noop() { }

/* 
 *  Function: timer_init
 *  ---------------------------------------------------
 *  This method initializes the timer subsystem by
 *  populating the timers array with blank, serviced
 *  timer objects. This allows the process_timers()
 *  method to work even if nothing has been actually
 *  entered into the system.
 */
void timer_init(void) {
  for (int i = 0; i < MAX_TIMERS; i++) {
    timers[i] = {
      noop,
      0,
      0,
      true,
    };
  }
}

/* 
 *  Function: _get_next_id
 *  ---------------------------------------------------
 *  Loops over each timer and checks for the first
 *  available (serviced=true) element and returns
 *  the id.
 */
int _get_next_id(void) {
  for (int i = 0; i < MAX_TIMERS; i++) {
    delay_timer_t timer = timers[i];
    if (timer.serviced == true) {
      return i;
    }
  }
}

/* 
 *  Function: process_timers
 *  ---------------------------------------------------
 *  Iterate over each timer and check if the underlying
 *  method is ready to be processed. If enough time has
 *  elapsed, invoke the referenced method and then set
 *  the timer to serviced=true.
 */
void process_timers(void) {
  for (int i = 0; i < MAX_TIMERS; i++) {
    delay_timer_t timer = timers[i];
    if (timer.serviced == false && millis() > timer.target_ms) {
      func method = timer.method;
      method();
      timers[i].serviced = true;
    }
  }
}

/* 
 *  Function: defer
 *  ---------------------------------------------------
 *  This method takes a function pointer and a duration
 *  and will add the function pointer to the timer 
 *  array, defering invocation until the specified time
 *  has elapsed.
 */
void defer(func fn, long unsigned int ms) {
  for (int i = 0; i < MAX_TIMERS; i++) {
    delay_timer_t timer = timers[i];
    // Do not allow enqueuing the same method multiple times.
    if (timer.serviced == false && timer.method == fn) {
      return;
    }
  }

  int timer_id = _get_next_id();
  timers[timer_id] = {
    fn,
    ms,
    millis() + ms,
    false,
  };
}

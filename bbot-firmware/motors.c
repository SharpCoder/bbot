#include <Arduino.h>
#include "motors.h"

#define MAX_PHASE 3
#define MIN_PHASE 0

int motor_phases[] = {0,0};
int shift_register_values[8] =  {0,0,0,0,0,0,0,0};

/* 
 *  Function: computeOffset
 *  -----------------------------
 *  This method computes the offset of a particular
 *  motor. The first motor has no offset, the second
 *  motor has an offset of 4. This is because
 *  the shift register has 8 channels and each motor
 *  uses a different set of them.
 */
int _computeOffset(motor_t motor) {
  if (motor == MotorRight) {
    return 4;
  } else {
    return 0;
  }
}

/* 
 *  Function: setPhase
 *  -----------------------------
 *  This method will take a motor and a phase
 *  and update the shift register data object
 *  while applying the result into the shift register.
 */
void _setPhase(motor_t motor, int phase) {
  int offset = _computeOffset(motor);
  for (int phase_idx = 0; phase_idx < 4; phase_idx++) {
    shift_register_values[offset + phase_idx] = 0;
  }
  shift_register_values[offset + phase] = 1;
  // TOOD: apply to shift register
  
}

/* 
 *  Function: _step
 *  -----------------------------
 *  This method will take a motor and a direction
 *  and update the stepper phase in order to achieve
 *  movement in the particular direction.
 */
void _step(motor_t motor, bool forward) {
  int index = _computeOffset(motor) / 4;

  // Compute the next phase
  if (forward) {
    motor_phases[index] = motor_phases[index] + 1;
  } else {
    motor_phases[index] = motor_phases[index] - 1;
  }

  // Handle boundary overflow
  if (motor_phases[index] > MAX_PHASE) {
    motor_phases[index] = MIN_PHASE;
  } else if (motor_phases[index] < MIN_PHASE) {
    motor_phases[index] = MAX_PHASE;
  }

  // Apply
  _setPhase(motor, motor_phases[index]);
}

/* 
 *  Function: stepForward
 *  -----------------------------
 *  This method will move a particular motor forwards.
 */
void stepForward(motor_t motor) {
  _step(motor, true);  
}

/* 
 *  Function: stepBackward
 *  -----------------------------
 *  This method will move a particular motor backwards.
 */
void stepBackward(motor_t motor) {
  _step(motor, false);
}

#include "motors.h"


// Which phase each motor is currently in
int motor_phases[] = {0,0};

/* Assuming index 0 - 3 is motor 1, 4 - 7 is motor 2. This map represents
 * a particular motor-phase and corresponds it to a pin on the shift register.
 * By using this map lookup, we can change which phase maps to which pin through a
 * global definition instead of making assumptions.
 */
int phase_pin_map[] = { MOTOR_1_A, MOTOR_1_C, MOTOR_1_B, MOTOR_1_D, MOTOR_2_A, MOTOR_2_C, MOTOR_2_B, MOTOR_2_D };

// This represents which shift register pins are currently HIGH.
int shift_register_values[8] =  {0,0,0,0,0,0,0,0};

/* 
 *  Function: _compute_offest
 *  ---------------------------------------------------
 *  This method computes the offset of a particular
 *  motor. The first motor has no offset, the second
 *  motor has an offset of 4. This is because
 *  the shift register has 8 channels and each motor
 *  uses a different set of them.
 */
int _compute_offest(motor_t motor) {
  if (motor == MotorRight) {
    return 4;
  } else {
    return 0;
  }
}

/* 
 *  Function: _set_phase
 *  ---------------------------------------------------
 *  This method will take a motor and a phase
 *  and update the shift register data object
 *  while applying the result into the shift register.
 */
void _set_phase(motor_t motor, int phase) {
  int offset = _compute_offest(motor);
  for (int phase_idx = 0; phase_idx < 4; phase_idx++) {
    // For a given index, lookup the pin mapping
    int phase_pin = phase_pin_map[offset + phase_idx];
    // Then we can zero out the particular pin in question
    shift_register_values[phase_pin] = 0;
  }

  // For the selected phase, lookup the pin mapping
  int phase_pin = phase_pin_map[offset + phase];
  shift_register_values[phase_pin] = 1;

  // Use the shift.h function to apply values.
  update_shift_registers(shift_register_values);  
}

/* 
 *  Function: _step
 *  ---------------------------------------------------
 *  This method will take a motor and a direction
 *  and update the stepper phase in order to achieve
 *  movement in the particular direction.
 */
void _step(motor_t motor, bool forward) {
  int index = _compute_offest(motor) / 4;

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
  _set_phase(motor, motor_phases[index]);
}

/* 
 *  Function: stepForward
 *  ---------------------------------------------------
 *  This method will move a particular motor forwards.
 */
void step_forward(motor_t motor) {
  _step(motor, true);  
}

/* 
 *  Function: stepBackward
 *  ---------------------------------------------------
 *  This method will move a particular motor backwards.
 */
void step_backward(motor_t motor) {
  _step(motor, false);
}

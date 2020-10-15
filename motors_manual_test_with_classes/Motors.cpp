#include "Motors.h"

motors_c::motors_c(byte set_L_PWM_PIN, byte set_L_DIR_PIN, byte set_R_PWM_PIN , byte set_R_DIR_PIN) : L_PWM_PIN(set_L_PWM_PIN), L_DIR_PIN(set_L_DIR_PIN), R_PWM_PIN(set_R_PWM_PIN), R_DIR_PIN(set_R_DIR_PIN) {
  // Set our motor driver pins as outputs.
  pinMode( L_PWM_PIN, OUTPUT );
  pinMode( L_DIR_PIN, OUTPUT );
  pinMode( R_PWM_PIN, OUTPUT );
  pinMode( R_DIR_PIN, OUTPUT );

  // Set initial direction for l and r
  digitalWrite( L_DIR_PIN, HIGH  );
  digitalWrite( R_DIR_PIN, HIGH );
}

motors_c::~motors_c(){}

motors_c::forward() {
  // Send power PWM to pins, to motor drivers.
  analogWrite( L_PWM_PIN, 100 );
  analogWrite( R_PWM_PIN, 100 );
}

motors_c::left() {
  // Send power PWM to pins, to motor drivers.
  analogWrite( L_PWM_PIN, 100 );
  analogWrite( R_PWM_PIN, 0 );
}

motors_c::right() {
  // Send power PWM to pins, to motor drivers.
  analogWrite( L_PWM_PIN, 0 );
  analogWrite( R_PWM_PIN, 100 );
}

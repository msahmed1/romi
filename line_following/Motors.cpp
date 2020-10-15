#include "Motors.h"

motors_c::motors_c(byte set_L_PWM_PIN, byte set_L_DIR_PIN, byte set_R_PWM_PIN , byte set_R_DIR_PIN) : L_PWM_PIN(set_L_PWM_PIN), L_DIR_PIN(set_L_DIR_PIN), R_PWM_PIN(set_R_PWM_PIN), R_DIR_PIN(set_R_DIR_PIN) {
  // Set our motor driver pins as outputs.
  pinMode( L_PWM_PIN, OUTPUT );
  pinMode( L_DIR_PIN, OUTPUT );
  pinMode( R_PWM_PIN, OUTPUT );
  pinMode( R_DIR_PIN, OUTPUT );

  // Set initial direction for l and r
  digitalWrite( L_DIR_PIN, LOW  );
  digitalWrite( R_DIR_PIN, LOW );
}

motors_c::~motors_c() {}

motors_c::steering(float dir) {
  float dead_band = 15;
  float max_power = 75;

  if (dir < -0.2 || dir > 0.2) {
    digitalWrite( L_DIR_PIN, dir < 0 ? HIGH : LOW );
    digitalWrite( R_DIR_PIN, dir < 0 ? LOW : HIGH );

    analogWrite( L_PWM_PIN, dir * max_power * (dir < 0 ? -1 : 1) );
    analogWrite( R_PWM_PIN, dir * max_power * (dir < 0 ? -1 : 1) );
  } else {
    digitalWrite( L_DIR_PIN, LOW );
    digitalWrite( R_DIR_PIN, LOW );
    
    // Send power PWM to pins, to motor drivers.
    analogWrite( L_PWM_PIN, 50 );
    analogWrite( R_PWM_PIN, 50 );
  }
}

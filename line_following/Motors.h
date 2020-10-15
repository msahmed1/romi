#ifndef MY_MOTORS_H
#define MY_MOTORS_H

#include "arduino.h"

class motors_c {
  public:
    motors_c( byte set_L_PWM_PIN, byte set_L_DIR_PIN, byte set_R_PWM_PIN , byte set_R_DIR_PIN );
    ~motors_c();

    steering(float dir);
    breaks() {
      analogWrite( L_PWM_PIN, 0 );
      analogWrite( R_PWM_PIN, 0 );
    }

  private:
    byte L_PWM_PIN;
    byte L_DIR_PIN;
    byte R_PWM_PIN;
    byte R_DIR_PIN;

};

#endif

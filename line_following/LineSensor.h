#ifndef Line_Sensor_H
#define Line_Sensor_H

#include "arduino.h"
#include "Motors.h"

class lineSensor_c {
  public:
    lineSensor_c(const motors_c &motors, byte LINE_LEFT, byte LINE_CENTER, byte LINE_RIGHT);
    ~lineSensor_c();

    void begin();
    
    void followLine();

  private:
    motors_c myMotors;

    byte LINE_LEFT_PIN;
    byte LINE_CENTRE_PIN;
    byte LINE_RIGHT_PIN;

    //variables for calibration
    int left_bias = 0;
    int center_bias = 0;
    int right_bias = 0;
    int sample_count = 0;

    float WeightedLineSensingBangBang(float left, float center, float right);
};

#endif

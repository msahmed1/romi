#ifndef QTR_3A_IR_Sensor_H
#define QTR_3A_IR_Sensor_H

#include "arduino.h"
#include "Motors.h"

class reflectanceSensor_c {
  public:
    reflectanceSensor_c(const motors_c &motors, byte LINE_LEFT, byte LINE_CENTER, byte LINE_RIGHT);
    ~reflectanceSensor_c();

    bool calibrationSequence();

    void BangBang();
    
    bool readCalibratedLeft();
    bool readCalibratedCenter();
    bool readCalibratedRight();

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
};

#endif

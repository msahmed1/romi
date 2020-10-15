#ifndef QTR_3A_Sensor_H
#define QTR_3A_Sensor_H

class reflectanceSensor_c {
  public:
    reflectanceSensor_c(byte LINE_LEFT, byte LINE_CENTER, byte LINE_RIGHT);
    reflectanceSensor_c();
    ~reflectanceSensor_c();
    
    void calibration sequence();

  private:
    byte LINE_LEFT_PIN;
    byte LINE_CENTRE_PIN;
    byte LINE_RIGHT_PIN;
}

#endif

#include "QTR_3A_Sensor.h"

reflectanceSensor_c::reflectanceSensor_c(byte LINE_LEFT, byte LINE_CENTER, byte LINE_RIGHT) : LINE_LEFT_PIN(LINE_LEFT), LINE_CENTRE_PIN(LINE_CENTER), LINE_RIGHT_PIN(LINE_RIGHT) {}

reflectanceSensor_c::reflectanceSensor_c() : LINE_LEFT_PIN(A2), LINE_CENTRE_PIN(A3), LINE_RIGHT_PIN(A4) {}

reflectanceSensor_c::~reflectanceSensor_c(){}

void reflectanceSensor_c::begin(){
  //Calibrate sensor reading
}

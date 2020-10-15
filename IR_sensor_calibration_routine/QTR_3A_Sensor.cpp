#include "QTR_3A_Sensor.h"

reflectanceSensor_c::reflectanceSensor_c(byte LINE_LEFT, byte LINE_CENTER, byte LINE_RIGHT) : LINE_LEFT_PIN(LINE_LEFT), LINE_CENTRE_PIN(LINE_CENTER), LINE_RIGHT_PIN(LINE_RIGHT) {
  pinMode(LINE_LEFT_PIN, INPUT);
  pinMode(LINE_CENTRE_PIN, INPUT);
  pinMode(LINE_RIGHT_PIN, INPUT);
}

reflectanceSensor_c::~reflectanceSensor_c() {}

bool reflectanceSensor_c::calibrationSequence() {
  if (sample_count < 100) {
    //increment sample count
    sample_count++;

    // To store result.
    int l_value; // left sensor
    int c_value; // centre sensor
    int r_value; // right sensor

    // Read analog voltages and calculate running average
    l_value = analogRead( LINE_LEFT_PIN );
    left_bias -= left_bias / sample_count;
    left_bias += l_value / sample_count;

    c_value = analogRead( LINE_CENTRE_PIN );
    center_bias -= center_bias / sample_count;
    center_bias += c_value / sample_count;

    r_value = analogRead( LINE_RIGHT_PIN );
    right_bias -= right_bias / sample_count;
    right_bias += r_value / sample_count;


    return false;
  }
  return true;
}

int reflectanceSensor_c::readCalibratedLeft() {
  return analogRead( LINE_LEFT_PIN ) - left_bias;
}

int reflectanceSensor_c::readCalibratedCenter() {
  return analogRead( LINE_CENTRE_PIN ) - center_bias;
}

int reflectanceSensor_c::readCalibratedRight() {
  return analogRead( LINE_RIGHT_PIN ) - right_bias;
}

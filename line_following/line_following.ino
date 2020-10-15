// If the speed is to high the robot can't keep up with control algorithum

#import "LineSensor.h";
#import "Motors.h";

motors_c myMotors(10, 16, 9, 15);
lineSensor_c lineFollower(myMotors,A2, A3, A4);

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
}

void loop()
{
  if (lineFollower.calibrationSequence()) {
    Serial.println(lineFollower.WeightedLineSensingBangBang());
  }

  delay(50);
}

// If the speed is to high the robot can't keep up with control algorithum

#import "QTR_3A_Sensor.h";
#import "Motors.h";

motors_c myMotors(10, 16, 9, 15);
reflectanceSensor_c myIRSensor(myMotors,A2, A3, A4);

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
}

void loop()
{
  if (myIRSensor.calibrationSequence()) {
    Serial.print( myIRSensor.readCalibratedLeft() );
    Serial.print( ", " );
    Serial.print( myIRSensor.readCalibratedCenter() );
    Serial.print( ", " );
    Serial.print( myIRSensor.readCalibratedRight() );
    Serial.print( "\n" );
    myIRSensor.BangBang();
  }

  delay(50);
}

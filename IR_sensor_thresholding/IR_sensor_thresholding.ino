#import "QTR_3A_Sensor.h";

reflectanceSensor_c myIRSensor(A2, A3, A4);

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
}

void loop()
{

  //  Serial.print("left bias: ");
  //  Serial.println(myIRSensor.getLeftBias());
  //
  //  Serial.print("Sample Count: ");
  //  Serial.println(myIRSensor.getSampleCount());

  if (myIRSensor.calibrationSequence()) {
    Serial.print( myIRSensor.readCalibratedLeft() );
    Serial.print( ", " );
    Serial.print( myIRSensor.readCalibratedCenter() );
    Serial.print( ", " );
    Serial.print( myIRSensor.readCalibratedRight() );
    Serial.print( "\n" );
  }

  delay(50);
}

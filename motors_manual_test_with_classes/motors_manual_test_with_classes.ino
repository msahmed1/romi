#import "Motors.h";

motors_c myMotors(10, 16, 9, 15);

// Setup, only runs once when powered on.
void setup() {
  // Start up the Serial for debugging.
  Serial.begin(9600);
  delay(1000);
  // Print reset so we can catch any reset error.
  Serial.println(" ***Reset*** ");

}


// put your main code here, to run repeatedly:
void loop() {

  myMotors.right();

  // Brief pause
  delay(250);

}

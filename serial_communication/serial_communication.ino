#define BAUD_RATE 9600

int number_of_flashes;

void flash_leds () {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
  number_of_flashes++;
}

// the setup function runs once when you press reset or power the board
void setup() {

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  //Start a serial connection
  Serial.begin(BAUD_RATE);

  // Wait for stable connection, report reset.
  delay(1000);
  Serial.println("***RESET***");

  number_of_flashes = 0;
}

// the loop function runs over and over again forever
void loop() {
  flash_leds();                     // flash LEDS
  Serial.print("Totoal Number of Flashes: ");
  Serial.println(number_of_flashes);
}

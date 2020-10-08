unsigned long last_timestamp_p13;   // We will store a timestamp in this.
unsigned long last_timestamp_p17;   // We will store a timestamp in this.
unsigned long last_timestamp_p30;   // We will store a timestamp in this.

// Remember: Setup only runs once when the arduino is powered up.
void setup() {

  pinMode(17, OUTPUT );        // Red LED (RX)
  pinMode(13, OUTPUT );        // Yellow LED
  pinMode(30, OUTPUT );        // Green LED (TX)

  last_timestamp_p13 = millis();    // We set an intial timestamp value.
  last_timestamp_p17 = millis();    // We set an intial timestamp value.
  last_timestamp_p30 = millis();    // We set an intial timestamp value.
}


// Remember: loop is called again and again.
void loop() {

  // Get how much time has passed right now.
  unsigned long time_now = millis();

  // Work out how many milliseconds have gone passed by subtracting
  // our two timestamps.  time_now will always be bigger than the
  // time_of_read (except when millis() overflows after 50 days).
  unsigned long elapsed_time_1 = time_now - last_timestamp_p13;
  unsigned long elapsed_time_2 = time_now - last_timestamp_p17;
  unsigned long elapsed_time_3 = time_now - last_timestamp_p30;

  // See if 1000 milliseconds have elapsed
  if ( elapsed_time_1 >= 1000 && elapsed_time_1 < 2000) {
    digitalWrite(13, HIGH);
  } else if ( elapsed_time_1 > 0 && elapsed_time_1 < 1000 ) {
    digitalWrite(13, LOW);
  } else {
    // Since 1000ms elapsed, we overwrite our last_timestamp with
    // the new current time so that another 1000ms is needed to pass.
    last_timestamp_p13 = millis();
  }

  if ( elapsed_time_2 >= 500 && elapsed_time_2 < 1000) {
    digitalWrite(17, HIGH);
  } else if ( elapsed_time_2 > 0 && elapsed_time_2 < 500 ) {
    digitalWrite(17, LOW);
  } else {
    last_timestamp_p17 = millis();
  }

  if ( elapsed_time_3 >= 250 && elapsed_time_3 < 500) {
    digitalWrite(30, HIGH);
  } else if ( elapsed_time_3 > 0 && elapsed_time_3 < 250 ) {
    digitalWrite(30, LOW);
  } else {
    last_timestamp_p30 = millis();
  }
}

// Define the LED and Switch Pins
int LEDs[] = {12, 11, 10, 9};
int Switches[] = {2, 3, 4, 5}; // Assume a 4-switch dipswitch connected to pins 2, 3, 4, 5

void setup() {
  // Initialize the LEDs and Switches
  for (int i = 0; i < 4; i++) {
    pinMode(LEDs[i], OUTPUT);
    pinMode(Switches[i], INPUT);
  }
}

void loop() {
  // Read each switch and control the corresponding LED
  for (int i = 0; i < 4; i++) {
    if (digitalRead(Switches[i]) == HIGH) {
      // Blink the LED if the switch is ON
      digitalWrite(LEDs[i], HIGH);
      delay(100);
      digitalWrite(LEDs[i], LOW);
      delay(100);
    } else {
      // Turn off the LED if the switch is OFF
      digitalWrite(LEDs[i], LOW);
    }
  }
}

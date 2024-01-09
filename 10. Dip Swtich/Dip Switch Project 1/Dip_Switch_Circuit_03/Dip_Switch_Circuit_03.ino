// Define the LED and Switch Pins
int LEDs[] = {12, 11, 10, 9};
int Switches[] = {2, 3, 4, 5}; // 4-switch dipswitch connected to pins 2, 3, 4, 5

void setup() {
  // Initialize the LEDs and Switches
  for (int i = 0; i < 4; i++) {
    pinMode(LEDs[i], OUTPUT);
    pinMode(Switches[i], INPUT);
  }
}

void loop() {
  // Read each switch and store it in a variable
  int pattern = 0;
  for (int i = 0; i < 4; i++) {
    pattern <<= 1;  // Shift bits to the left
    pattern |= digitalRead(Switches[i]);  // Read the switch and add it to pattern
  }

  // Perform different actions based on the pattern
  switch (pattern) {
    case 0b1010:  // Pattern 1: 1010
      // Do something (e.g., blink all LEDs once)
      for (int i = 0; i < 4; i++) {
        digitalWrite(LEDs[i], HIGH);
      }
      delay(200);
      for (int i = 0; i < 4; i++) {
        digitalWrite(LEDs[i], LOW);
      }
      delay(200);
      break;

    case 0b0101:  // Pattern 2: 0101
      // Do something else (e.g., alternate LEDs)
      digitalWrite(LEDs[0], HIGH);
      digitalWrite(LEDs[2], HIGH);
      delay(200);
      digitalWrite(LEDs[0], LOW);
      digitalWrite(LEDs[2], LOW);
      delay(200);
      digitalWrite(LEDs[1], HIGH);
      digitalWrite(LEDs[3], HIGH);
      delay(200);
      digitalWrite(LEDs[1], LOW);
      digitalWrite(LEDs[3], LOW);
      delay(200);
      break;

    case 0b1111:  // Pattern 3: 1111
      // Do yet something else (e.g., run LEDs in sequence)
      for (int i = 0; i < 4; i++) {
        digitalWrite(LEDs[i], HIGH);
        delay(100);
        digitalWrite(LEDs[i], LOW);
      }
      break;

    default:
      // Turn off all LEDs if no pattern is matched
      for (int i = 0; i < 4; i++) {
        digitalWrite(LEDs[i], LOW);
      }
      break;
  }
}

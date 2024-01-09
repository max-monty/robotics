const int buttonPin = 2; 
const int ledPin = 13; 
int currentState; // HIGH (pressed) or LOW (not pressed)
int lastState = LOW; // Last known state of the button

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  pinMode(buttonPin, INPUT); 
}

void loop() {
  currentState = digitalRead(buttonPin);

  // Check if the button was just pressed
  if (lastState == LOW && currentState == HIGH) {
    // Toggle the LED's state.
    digitalWrite(ledPin, !digitalRead(ledPin));
  }
  
  // Store the current button state 
  lastState = currentState;

  // Pause for 50 milliseconds to debounce the button press
  delay(50);
}

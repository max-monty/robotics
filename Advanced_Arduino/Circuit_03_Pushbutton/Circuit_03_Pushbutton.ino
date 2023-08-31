const int buttonPin = 2; 
const int ledPin = 13; 
int currentState; // HIGH or LOW.

int lastState = HIGH; // Last known state of the button. Initialized to HIGH (not pressed).
int ledState = LOW; // Current state of the LED (ON or OFF). Initialized to OFF (LOW).

void setup() {
  pinMode(ledPin, OUTPUT); 

  pinMode(buttonPin, INPUT); 
}

void loop() {
  currentState = digitalRead(buttonPin);

  // Check if the button was just pressed (transitioned from not pressed (HIGH) to pressed (LOW)).
  if (lastState == HIGH && currentState == LOW) {   
    
    // Toggle the LED's state. If it was ON, turn it OFF and vice versa.
    ledState = !ledState;

    // Set the LED to its new state.
    digitalWrite(ledPin, ledState);
  }
  
  // Store the current button state for comparison in the next loop iteration.
  lastState = currentState;

  // Pause for 50 milliseconds before the next loop iteration, for debouncing the button press.
  delay(50);
}

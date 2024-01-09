// Motor A
int directionPinA = 12;
int pwmPinA = 3;
int brakePinA = 9;

bool directionState;

void setup() {
  // Motor A
  pinMode(directionPinA, OUTPUT);
  pinMode(pwmPinA, OUTPUT);
  pinMode(brakePinA, OUTPUT);
}

void loop() {
  // Change direction every loop()
  directionState = !directionState;

  // Motor A
  if (directionState == false) {
    digitalWrite(directionPinA, LOW);
  } else {
    digitalWrite(directionPinA, HIGH);
  }

  // Release brakes for Motor A
  digitalWrite(brakePinA, LOW);
  
  // Set work duty for Motor A
  analogWrite(pwmPinA, 255);

  delay(2000);

  // Activate brakes for Motor A
  digitalWrite(brakePinA, HIGH);

  // Set work duty for Motor A to 0 (off)
  analogWrite(pwmPinA, 0);

  delay(2000);
}

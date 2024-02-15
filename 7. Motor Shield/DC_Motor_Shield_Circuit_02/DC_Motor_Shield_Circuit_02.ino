// Motor A
int directionPinA = 12;
int pwmPinA = 3;
int brakePinA = 9;

// Motor B
int directionPinB = 13;
int pwmPinB = 11;
int brakePinB = 8;

bool directionStat = false;

void setup() {
  // Motor A
  pinMode(directionPinA, OUTPUT);
  pinMode(pwmPinA, OUTPUT);
  pinMode(brakePinA, OUTPUT);

  // Motor B
  pinMode(directionPinB, OUTPUT);
  pinMode(pwmPinB, OUTPUT);
  pinMode(brakePinB, OUTPUT);
}

void loop() {
  // Change direction every loop()
  directionState = !directionState;

  // Motor A and Motor B
  if (directionState == false) {
    digitalWrite(directionPinA, LOW);
    digitalWrite(directionPinB, LOW);
  } else {
    digitalWrite(directionPinA, HIGH);
    digitalWrite(directionPinB, HIGH);
  }

  // Release brakes for both motors
  digitalWrite(brakePinA, LOW);
  digitalWrite(brakePinB, LOW);
  
  // Set work duty for both motors
  analogWrite(pwmPinA, 255);
  analogWrite(pwmPinB, 255);

  delay(2000);

  // Activate brakes for both motors
  digitalWrite(brakePinA, HIGH);
  digitalWrite(brakePinB, HIGH);

  // Set work duty for both motors to 0 (off)
  analogWrite(pwmPinA, 0);
  analogWrite(pwmPinB, 0);

  delay(2000);
}

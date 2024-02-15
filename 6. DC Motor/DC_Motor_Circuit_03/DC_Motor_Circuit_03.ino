// Existing motor definitions
int enablePin1 = 11; // Motor 1 Speed Control
int in1Pin = 10; // Motor 1 Direction
int in2Pin = 9; // Motor 1 Direction

// Additional motor definitions
int enablePin2 = 6; // Motor 2 Speed Control
int in3Pin = 5; // Motor 2 Direction
int in4Pin = 4; // Motor 2 Direction

int switchPin = 7; // Direction switch for Motor 1
int switchPin2 = 3; // Direction switch for Motor 2 (if needed)
int potPin = 0; // Speed control potentiometer

void setup() {
  // Setup for Motor 1
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(enablePin1, OUTPUT);

  // Setup for Motor 2
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
  pinMode(enablePin2, OUTPUT);

  pinMode(switchPin, INPUT_PULLUP); // Assuming both motors use the same switch
  // pinMode(switchPin2, INPUT_PULLUP); // Uncomment if using a separate switch for Motor 2
}

void loop() {
  int speed = analogRead(potPin) / 4;
  boolean reverse = digitalRead(switchPin);
  // Assuming you want both motors to behave the same
  setMotor(enablePin1, in1Pin, in2Pin, speed, reverse);
  setMotor(enablePin2, in3Pin, in4Pin, speed, reverse);
}

void setMotor(int enablePin, int inPin1, int inPin2, int speed, boolean reverse) {
  analogWrite(enablePin, speed);
  digitalWrite(inPin1, !reverse);
  digitalWrite(inPin2, reverse);
}

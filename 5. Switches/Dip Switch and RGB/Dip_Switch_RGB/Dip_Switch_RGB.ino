int redPin = 5;
int greenPin = 6;
int bluePin = 7;
int switchPin1 = 2;
int switchPin2 = 3;
int switchPin3 = 4;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(switchPin1, INPUT_PULLUP);
  pinMode(switchPin2, INPUT_PULLUP);
  pinMode(switchPin3, INPUT_PULLUP);
}

void loop() {
  // Read the status of the 3-pin DIP switch
  int switchState1 = digitalRead(switchPin1);
  int switchState2 = digitalRead(switchPin2);
  int switchState3 = digitalRead(switchPin3);
  // Determine the color to display based on the switch position
  int redValue = switchState1 == LOW ? 255 : 0;
  int greenValue = switchState2 == LOW ? 255 : 0;
  int blueValue = switchState3 == LOW ? 255 : 0;
  // Set the color of the RGB LED
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
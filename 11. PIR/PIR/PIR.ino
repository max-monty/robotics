// Assuming basic setup for an LED and PIR motion sensor

const int led = 9; // Led positive terminal to digital pin 9
const int sensor = 5; // Signal pin of sensor to digital pin 5
int state = LOW; // Variable to store the state, initialized to LOW
int val = 0; // Variable to store the read value from the sensor

void setup() {
  // This function runs once after each power-up or reset of the Arduino board
  pinMode(led, OUTPUT); // LED is set as an output
  pinMode(sensor, INPUT); // PIR motion sensor is set as an input
  Serial.begin(9600); // Begin serial communication at 9600 bps
}

void loop() {
  // This function runs over and over, and contains the main program
  val = digitalRead(sensor); // Read the sensor value
  if (val == HIGH) {
    digitalWrite(led, HIGH); // Turn LED on
    delay(500); // Delay of LED is 500ms
    if (state == LOW) {
      Serial.println("Motion detected");
      state = HIGH;
    }
  } else {
    digitalWrite(led, LOW); // Turn LED off
    delay(500); // Delay of LED is 500ms
    if (state == HIGH) {
      Serial.println("The action/motion has stopped");
      state = LOW;
    }
  }
}

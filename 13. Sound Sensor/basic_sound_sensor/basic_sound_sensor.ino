// Define the pin where the sound sensor is connected
const int soundSensorPin = 2; // Change to a digital pin, for example, D2
// Define the pin for the LED
const int ledPin = 13; // Assume LED is connected to digital pin 13

void setup() {
  // Begin serial communication at a baud rate of 9600
  Serial.begin(9600);
  // Initialize the sound sensor pin as an input
  pinMode(soundSensorPin, INPUT);
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read the value from the sound sensor
  int sensorValue = digitalRead(soundSensorPin);
  
  // Check if the sensor detected sound
  if (sensorValue == HIGH) {
    // Output "Sound Detected!" to the Serial Monitor
    Serial.println("Sound Detected!");
    // Turn the LED on
    digitalWrite(ledPin, HIGH);
  } else {
    // If no sound is detected, turn the LED off
    digitalWrite(ledPin, LOW);
  }
  
  // Wait for a short period to prevent flooding the serial output
  delay(10); // Delay of 10 milliseconds
}

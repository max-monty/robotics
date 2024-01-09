const int sensorPin = A0;
const int buttonPin = 5; // Button pin

// RGB LED pins
int redPin = 11;
int greenPin = 10;
int bluePin = 9;

// Variables for light level:
int lightLevel;
int maxThreshold = 0;     // Used for setting the "max" light level
int minThreshold = 1023;  // Used for setting the "min" light level

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT); 
  pinMode(bluePin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Setup button with internal pull-up resistor
  Serial.begin(9600);
}

void RGB_color(int red_value, int green_value, int blue_value) {
  analogWrite(redPin, red_value);
  analogWrite(greenPin, green_value);
  analogWrite(bluePin, blue_value);
}

void loop() { 
  // Check for button press
  if (digitalRead(buttonPin) == LOW) {
    calibrateSensor();  // Calibrate the sensor for 5 seconds
  }

  lightLevel = analogRead(sensorPin);  // Reads the voltage on the sensorPin
  lightLevel = map(lightLevel, minThreshold, maxThreshold, 0, 255); // Map using thresholds
  lightLevel = constrain(lightLevel, 0, 255); // Ensure it's within range

  Serial.println(lightLevel);   // Print the calibrated value

  // Use the calibrated lightLevel to determine the LED color
  if (lightLevel >= 0 && lightLevel < 64) {
    RGB_color(125, 0, 0); // red
  } else if (lightLevel >= 64 && lightLevel < 128) {
    RGB_color(125, 80, 0); // yellow-ish
  } else if (lightLevel >= 128 && lightLevel < 192) {
    RGB_color(0, 125, 125); // blue-ish
  } else if (lightLevel >= 192) {
    RGB_color(125, 125, 125); // white
  }
}

void calibrateSensor() {
  unsigned long startTime = millis();
  while (millis() - startTime < 10000) {  // For 10 seconds
    lightLevel = analogRead(sensorPin);
    if (lightLevel < minThreshold) {
      minThreshold = lightLevel;
    }
    if (lightLevel > maxThreshold) {
      maxThreshold = lightLevel;
    }
    delay(10); // Small delay to prevent overloading the microcontroller
  }
}

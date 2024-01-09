#include <Wire.h>  // Includes Wire library for I2C
#include <LiquidCrystal_I2C.h>  // Includes LiquidCrystal_I2C library

// Creates an LCD object. Parameters: (I2C address, Number of columns, Number of rows)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Defines pin numbers for the Ultrasonic Sensor
const int trigPin = 9;
const int echoPin = 10;

// Defines variables
long duration;
int distance;

void setup() {
  // Initializes the I2C communication between the Arduino and the LCD.
  // Wire the SDA port to A4 and the SCL port to A5 on the Arduino
  lcd.begin(16, 2);  
  lcd.backlight(); // Turn on the backlight

  // Sets the trigPin as an Output and echoPin as an Input
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Starts the serial communication
  Serial.begin(9600);
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance in cm
  distance = duration * 0.034 / 2;

  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  // Prints the distance on the I2C LCD
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm     ");  // Extra spaces to clear previous characters if any

  delay(1000);  // Delay for readability
}

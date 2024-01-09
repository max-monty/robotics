#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize LiquidCrystal_I2C library with I2C address 0x27 and 16 columns x 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int inPin = 0;  // A0 is where you connect the sensor

void setup()
{
  lcd.begin();       // Initialize the I2C LCD
  lcd.backlight();   // Turn on backlight
  Serial.begin(9600); // Initialize serial communication at 9600 baud rate
}

void loop() {
  int value = analogRead(inPin); // read the value from the sensor
  float millivolts = (value / 1024.0) * 5000;
  float celsius = millivolts / 10;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(celsius);
  lcd.print("C");
  lcd.setCursor(0, 1);
  float fahrenheit = (celsius * 9) / 5 + 32;
  lcd.print(fahrenheit); // converting the celsius into fahrenheit
  lcd.print("F");
  delay(1000);

  // Print values to Serial Monitor
  Serial.print("Celsius: ");
  Serial.print(celsius);
  Serial.print("  |  Fahrenheit: ");
  Serial.println(fahrenheit);
}

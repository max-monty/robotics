#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Digital pins
const int inPin = 0;  // A0 is where you connect the sensor

void setup()
{
  lcd.begin(16,2);
  Serial.begin(9600); // Initialize serial communication at 9600 baud rate
}

void loop() {
  int value = analogRead(inPin); // read the value from the sensor
  lcd.setCursor(0,1);
  float millivolts = (value / 1024.0) * 5000;
  float celsius = millivolts / 10;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(celsius);
  lcd.print("C");
  lcd.setCursor(0,1);
  float fahrenheit = (celsius * 9)/5 + 32;
  lcd.print(fahrenheit); //turning the celsius into fahrenheit
  lcd.print("F");
  delay(1000);

  // Print values to Serial Monitor
  Serial.print("Celsius: ");
  Serial.print(celsius);
  Serial.print("  |  Fahrenheit: ");
  Serial.println(fahrenheit);
}

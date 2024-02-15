#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize LiquidCrystal_I2C library with I2C address 0x27 and 16 columns x 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

// initialize our variables
int sensorPin = 0;
int tempC, tempF;

void setup() {
  // Initialize the I2C LCD
  lcd.init();
  lcd.backlight(); // Turn on the backlight
}

void loop() {
  tempC = get_temperature(sensorPin);
  tempF = celsius_to_fahrenheit(tempC);
  lcd.setCursor(0, 0);
  lcd.print(tempF);
  lcd.print(" ");
  lcd.print((char)223);  // Degree symbol
  lcd.print("F");
  delay(200);
}

int get_temperature(int pin) {
  // Read the value on the analog pin
  int temperature = analogRead(pin);
  // Calculate the temperature based on the reading
  float voltage = temperature * 5.0;
  voltage = voltage / 1024.0;
  return ((voltage - 0.5) * 100);
}

int celsius_to_fahrenheit(int temp) {
  return (temp * 9 / 5) + 32;
}

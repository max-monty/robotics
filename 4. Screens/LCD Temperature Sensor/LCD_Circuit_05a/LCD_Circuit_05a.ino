#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// initialize our variables
int sensorPin = 0;
int tempC, tempF;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  tempC = get_temperature(sensorPin);
  tempF = celsius_to_fahrenheit(tempC);
  lcd.setCursor(0,0);
  lcd.print(tempF); lcd.print(" "); lcd.print((char)223);
  lcd.print("F");
  delay(200);
}

int get_temperature(int pin) {
  // We need to tell the function which pin the sensor ishooked up to. We're using
  // the variable pin for that above
  // Read the value on that pin
  int temperature = analogRead(pin);
  // Calculate the temperature based on the reading and send that value back
  float voltage = temperature * 5.0;
  voltage = voltage / 1024.0;
  return ((voltage - 0.5) * 100);
}

int celsius_to_fahrenheit(int temp) {
  return (temp * 9 / 5) + 32;
}
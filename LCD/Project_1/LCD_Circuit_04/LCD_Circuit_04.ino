#include <LiquidCrystal_I2C.h>

int totalColumns = 16;
 int totalRows = 2;

LiquidCrystal_I2C lcd(0x27, totalColumns, totalRows);

byte customChar[8] = {
  0b00000,
  0b00100,
  0b00100,
  0b11111,
  0b00100,
  0b00100,
  0b00000,
  0b00000
};


void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, customChar);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.write(0);
}
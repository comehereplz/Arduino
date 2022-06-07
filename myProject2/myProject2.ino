#include <LiquidCrystal.h>

LiquidCrystal lcd (2, 3, 4, 5, 6, 7);

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  lcd.clear();
  float value = analogRead(A0);
  float volt = map(value, 0.0, 1023.0, 0.0, 5.0);

  lcd.print("value: ");
  lcd.setCursor(10, 0);
  lcd.print(value);
  lcd.setCursor(0, 1);
  lcd.print("volt: ");
  lcd.setCursor(10, 1);
  lcd.print(volt);
  lcd.print(" v");
  delay(500);
}

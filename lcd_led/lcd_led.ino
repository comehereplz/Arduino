#include <LiquidCrystal.h>

LiquidCrystal lcd {2,3,4,5,6,7};

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  lcd.clear();
  int value = analogRead(A0);
  int bright = map(value, 0, 1023, 0, 255);
  analogWrite(9, bright);

  lcd.print("value: ");
  lcd.setCursor(12,0);
  lcd.print(value);
  lcd.setCursor(0,1);
  lcd.print("bright: ");
  lcd.setCursor(12,1);
  lcd.print(bright);
  delay(300);
}

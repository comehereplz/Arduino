#include <LiquidCrystal.h>

LiquidCrystal lcd {2,3,4,5,6,7};

void setup() {
  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.begin(16, 2);
  lcd.clear();
  delay(1000);
}

void loop() {
  lcd.clear();
  while(Serial.available() > 0) {
    lcd.write(Serial.read());
  }
  delay(5000);
}

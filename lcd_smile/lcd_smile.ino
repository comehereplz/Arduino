#include <LiquidCrystal.h>

LiquidCrystal lcd {2, 3, 4, 5, 6, 7};

uint8_t smile[8] = {0x00, 0x0A, 0x0A, 0x00, 0x11, 0x0E, 0x00};

void setup() {
  lcd.createChar(1, smile); // 생성 문자를 CGRAM 1에 씀

  lcd.begin(16, 2);
  lcd.setCursor(8, 0); // 문자 표시 위치 지정
  lcd.write(1);
}

void loop() {
  // 아무것도 하지 않음
}

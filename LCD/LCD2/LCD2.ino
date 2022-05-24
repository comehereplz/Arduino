#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

uint8_t read_han[8] = {0x0A, 0x1E, 0x0A, 0x17, 0x0A, 0x10, 0x1F};
uint8_t read_kook[8] = {0x1F, 0x01, 0x02, 0x1F, 0x04, 0x1F, 0x01, 0x02};

void setup() {
  lcd.createChar(1, read_han);    // 생성문자를 CGRAM 1에 씀
  lcd.createChar(2, read_kook);   // 생성문자를 CGRAM 2에 씀
  lcd.begin(16, 2);
  lcd.setCursor(8, 0);            // 문자 표시 위치 지정
  lcd.write(1);
  lcd.write(2);
}

void loop() {
                                  // 아무것도 하지 않음
}

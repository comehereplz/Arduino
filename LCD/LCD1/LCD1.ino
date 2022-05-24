#include <LiquidCrystal.h>

LiquidCrystal lcd (2, 3, 4, 5, 6, 7);   // LCD핀과 라이브러리 초기화

void setup() {
  lcd.begin(16, 2);             // 16x2 문자형 LCD 사용
  lcd.print ("I LOVE YOU <3");  // 문자열 출력
}

void loop() {
  lcd.noDisplay ();     // 표시 끄기
  delay(500);           // 500ms 지연

  lcd.display ();       // 표시 켜기
  delay(500);           // 500ms 지연
}

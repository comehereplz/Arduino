#include <LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,5,6,7);

int sirenPin = 8;
int trigPin = 12; // 트리거 핀 12번 핀에 연결
int echoPin = 13; // 에코 핀 13번 핀에 연결

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  pinMode(trigPin, OUTPUT); // 트리거 핀 출력으로 설정
  pinMode(echoPin, INPUT);  // 에코 핀 입력으로 설정
  Serial.begin(9600);
  Serial.println("HC-SR04. distance measure start!");
  Serial.println();
}

void loop() {
  lcd.clear();
  float duration, cm;

  digitalWrite(trigPin, HIGH);  // 트리거 핀 HIGH 펄스
  delayMicroseconds(10);  // 10us 지연
  digitalWrite(trigPin, LOW); // 8 Cycle 초음파 출력

  duration = pulseIn(echoPin, HIGH);  // HIGH가 유지된 시간 반환
  cm = duration / 58.0; // 거리 = 왕복에 걸린 시간 / 50

  lcd.print("distance: ");
  lcd.setCursor(10,0);
  lcd.print(cm);
  lcd.print("cm");
  Serial.print("distance: ");
  Serial.print(cm);
  Serial.println(" cm");
  delay(500);

}

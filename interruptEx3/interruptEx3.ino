#include <MsTimer2.h>

int count = 0;
const byte ledPin = 13;
volatile byte ledState = LOW;

void numCount() { // ISR
  Serial.println(count++);  // ISR 호출 시 카운트 값 출력
  ledState = !ledState; // ISR 호출 시 LED 상태 값 반전
}

void setup() {
  pinMode(ledPin, OUTPUT);  // 13번 핀을 출력으로 설정
  Serial.begin(9600); // 시리얼 통신 속도 초기화
  MsTimer2::set(500, numCount); // 500ms 주기로 numCount ISR 호출
  MsTimer2::start();  // 타이머 인터럽트 활성화
}

void loop() {
  digitalWrite(ledPin, ledState);
}

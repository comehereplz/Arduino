#include <Servo.h>  // Servo 헤더 파일 추가

Servo myservo;  // 서보 제어를 위한 오브젝트 생성

int pos = 0;  // 서보 위치 저장 변수 초기화
const byte interruptPin = 2;

void setup() {
  myservo.attach(9);  // 9번 핀에 서보 모터 신호선 연결
  pinMode(interruptPin, INPUT_PULLUP);  // 2번 핀 내부 풀업 저항 사용
  attachInterrupt(digitalPinToInterrupt(interruptPin), door_open, FALLING);
}

void loop() {
  while (pos) {
    myservo.write(pos); // 0도부터 1도 씩 감소
    pos--;
    delay(15);  // 15ms 지연
  }
}

void door_open() {
  pos = 180;
}

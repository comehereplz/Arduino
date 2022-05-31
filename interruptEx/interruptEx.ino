const byte ledPin =13;
const byte interruptPin = 2;
volatile byte buttonState = LOW;  // ISR에 사용된 전역 변수는 volatile로 선언

void setup() {
  pinMode(ledPin,OUTPUT); // 13번 핀을 출력으로 설정
  pinMode(interruptPin, INPUT_PULLUP);  // 2번 핀 내부 풀업 저항으로 사용
  attachInterrupt(digitalPinToInterrupt(interruptPin),blink,FALLING);
}

void loop() {
  digitalWrite(ledPin,buttonState); // 13번 핀에 state 변수의 상태 값 반영
}

void blink() {
  buttonState = !buttonState; // 인터럽트 발생 시 변수 값 반전
}

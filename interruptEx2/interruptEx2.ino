const byte ledPin = 13;
const byte interruptPin = 2;
int count;

void setup() {
  pinMode(ledPin, OUTPUT); // 13번 핀을 출력으로 설정
  pinMode(interruptPin, INPUT_PULLUP);  // 2번 핀 내부 풀업 저항 사용
  attachInterrupt(digitalPinToInterrupt(interruptPin), counter, FALLING);
}

void loop() {
  Serial.println(count);
  delay(300);
}

void counter() {
  count++;
}

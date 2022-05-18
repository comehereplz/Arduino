#define LED_RED 3       // 빨간불 핀 번호 3
#define LED_YELLOW 4    // 노란불 핀 번호 4
#define LED_GREEN 5     // 초록불 핀 번호 5

void setup() {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
}

void loop() {
  turnOffAll();     // LED 다 끕니다.

  digitalWrite(LED_RED, HIGH);   // 빨간불 켜기
  delay(3000);    // 3초 간 유지
  turnOffAll();   // 불 다 끄기

  digitalWrite(LED_GREEN, HIGH);    // 초록불 켜기
  delay(3000);    // 3초 간 유지
  turnOffAll();   // 불 다 끄기

  digitalWrite(LED_YELLOW, HIGH);   // 노란불 켜기
  delay(2000);    // 2초 간 유지
  turnOffAll();   // 불 다 끄기
}

void turnOffAll() {     // turnOffAll 함수 정의
  digitalWrite(LED_RED, LOW);   // 빨간불 끄기
  digitalWrite(LED_YELLOW, LOW);   // 노란불 끄기
  digitalWrite(LED_GREEN, LOW);   // 초록불 끄기
}

#define LED_RED 13       // 빨간불 핀 번호 13
#define LED_GREEN 12     // 초록불 핀 번호 12

SoftwareSerial btSerial(2, 3); // Rx, Tx

void setup() {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);

  Serial.begin(9600);     // 9600 속도로 시리얼 통신을 시작한다
  btSerial.begin(9600);   // 9600 속도로 블루투스 시리얼 통신을 시작한다
}

void loop() {
  int colorSet = 1;

  turnOffAll();     // LED 다 끕니다.

  if (colorSet == 1) {            // 빨간불일 때
    digitalWrite(LED_RED, HIGH);  // 빨간불 켜기
    Serial.println("RED");       // 시리얼통신에 RED 출력
    btSerial.println("RED");
    delay(7000);      // 7초동안 빨간불 유지
    turnOffAll();     // 불 다 끄기
    colorSet = 2;     // 초록불로 변경
  }
  else if (colorSet == 2) {          // 초록불일 때
    digitalWrite(LED_GREEN, HIGH);   // 초록불 켜기
    Serial.println("GREEN");         // 시리얼통신에 GREEN 출력
    btSerial.println("GREEN");
    delay(7000);      // 7초동안 초록불 유지
    turnOffAll();     // 불 다 끄기
    colorSet = 1;       // 빨간불로 변경
  }
}

void turnOffAll() {     // turnOffAll 함수 정의
  digitalWrite(LED_RED, LOW);   // 빨간불 끄기
  digitalWrite(LED_GREEN, LOW);   // 초록불 끄기
}

#include <SoftwareSerial.h>   // SoftwareSerial을 통해 블루투스와 데이터 전송

#define LED_RED 13       // 빨간불 핀 번호 13
#define LED_GREEN 12     // 초록불 핀 번호 12

SoftwareSerial BTserial = SoftwareSerial(2, 3); // Rx, Tx

void setup() {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);

  Serial.begin(115200);     // 115200 속도로 시리얼 통신을 시작한다
  BTserial.begin(115200); // 115200 속도로 블루투스 시리얼 통신을 시작한다
}

void loop() {

  digitalWrite(LED_RED, HIGH);
  Serial.println(" RED ");
  colorSet();
  delay(7000);
  turnOffAll();

  digitalWrite(LED_GREEN, HIGH);
  Serial.println(" GREEN ");
  colorSet();
  delay(7000);
  turnOffAll();
}

void turnOffAll() {     // turnOffAll 함수 정의
  digitalWrite(LED_RED, LOW);   // 빨간불 끄기
  digitalWrite(LED_GREEN, LOW);   // 초록불 끄기
}

int colorSet() {
  if (LED_RED == HIGH) {
    BTserial.println("RED");
    return "RED";
  }

  if (LED_GREEN == HIGH) {
    BTserial.println("GREEN");
    return "GREEN";
  }
}

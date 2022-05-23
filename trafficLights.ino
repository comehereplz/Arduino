#define LED_RED 13       // 빨간불 핀 번호 13
#define LED_YELLOW 12    // 노란불 핀 번호 12
#define LED_GREEN 11     // 초록불 핀 번호 11

#include <SoftwareSerial.h>   // SoftwareSerial을 통해 블루투스와 데이터 전송

SoftwareSerial BTserial(2,3);  // Rx, Tx

int result = 1;

void setup() {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);

  Serial.begin(9600);     // 9600 속도로 시리얼 통신을 시작한다
  BTserial.begin(9600);   // 9600 속도로 블루투스 시리얼 통신을 시작한다
}

void loop() {
  turnOffAll();     // LED 다 끕니다.

    if(result == 1) {
      digitalWrite(LED_RED, HIGH);
      Serial.println("RED");
      delay(7000);
      turnOffAll();
      result = 2;
    }
    else if(result == 2) {
      digitalWrite(LED_YELLOW, HIGH);
      Serial.println("YELLOW");
      delay(1000);
      turnOffAll();
      result = 3;
    }
    else if(result == 3) {
      digitalWrite(LED_GREEN, HIGH);
      Serial.println("GREEN");
      delay(7000);
      turnOffAll();
      result = 1;
    }
 }

void turnOffAll() {     // turnOffAll 함수 정의
  digitalWrite(LED_RED, LOW);   // 빨간불 끄기
  digitalWrite(LED_YELLOW, LOW);   // 노란불 끄기
  digitalWrite(LED_GREEN, LOW);   // 초록불 끄기
}

#include <Servo.h>
#include <SoftwareSerial.h>   // Serial 통신을 하기 위해 선언

SoftwareSerial BTSerial(2,3); 
const int LED = 13;       // LED 13번 핀 연결
int sensor_value1 = 111;  // LED ON일 때 서브모터 각도
int sensor_value2 = 59;   // LED OFF일 때 서브모터 각도

Servo myServo;

void setup() {
  Serial.begin(9600);
  Serial.println("1 : LED ON  /  0 : LED OFF");
  Serial.println("----------------------------");

  BTSerial.begin(9600);
  pinMode(LED,OUTPUT);
  
  myServo.attach(5);
}

void loop() {
  if(BTSerial.available())      // 데이터가 수신되면
  {
    char toSend = (char)BTSerial.read();  // 문자 형 데이터로 저장

    Serial.print("Command = ");   // 수신된 데이터를
    Serial.println(toSend);       // 시리얼 모니터 창에 출력

    switch(toSend)        // 수신된 데이터가
    {
      case '1':           // '1'이면
              myServo.write(sensor_value1); // 서보모터 회전
              
              Serial.println("LED ON");   // 문자열 출력
              digitalWrite(LED,HIGH);     // LED ON
              break;
      case '0':           // '0'이면
              myServo.write(sensor_value2);  // 서보모터 회전
              
              Serial.println("LED OFF");   // 문자열 출력
              digitalWrite(LED,LOW);       // LED OFF
              break;
    }
  }
}

#include <Servo.h>

Servo myservo;
int pos1 = 111;   // LED ON일 때 서브모터 각도
int pos2 = 59;    // LED OFF일 때 서브모터 각도
const int ledPin = 13;    // LED 13번

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  
  myservo.attach(5);
}

void loop() {
  if(Serial.available()>0)
  {
    int button_cmd = Serial.read();

    if(button_cmd == '1')       // 1을 입력했을 때 
    {
        myservo.write(pos1);    // 서보모터 pos1(111)만큼 회전
        delay(15);
       
        digitalWrite(ledPin, HIGH);   // LED ON
        Serial.println("LED ON");
       }
      
      else if(button_cmd == '0')    // 0을 입력했을 때
      {
       
        myservo.write(pos2);     // 서보모터 pos2(59)만큼 회전
        delay(15);
      
        digitalWrite(ledPin, LOW);    // LED OFF
        Serial.println("LED OFF");
      }
    else
    {
      Serial.println("Unknown command!");
      Serial.println("Pushbutton command input : ");
    }
  }
}

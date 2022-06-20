const int sensorPin = A0; // 광센서값을 측정하기 위한 핀. A0에 연결
const int ledPin = 13;   // 아두이노 보드 13번 LED로 수정

int sensorValue = 0;  // 센서 변수 초기화
int sensorMin = 1023; // 센서 최솟값 1023으로 초기화
int sensorMax = 0;  // 센서 최댓값 0으로 초기화

void setup() {
  pinMode(ledPin, OUTPUT);  // 13번 핀 출력 설정
  digitalWrite(ledPin, HIGH); // LED ON

  while (millis() < 5000) { // 처음 5초 동안 센서값 읽음
    sensorValue = analogRead(sensorPin);  // 센서값 읽음
    if (sensorValue > sensorMax) {  // 센서 최댓값 체크
      sensorMax = sensorValue;  // 센서 최댓값 변수에 저장
    }

    if (sensorValue < sensorMin) {  // 센서 최솟값 체크
      sensorMin = sensorValue;  // 센서 최솟값 변수에 저장
    }
  }
  digitalWrite(ledPin, LOW);  // LED OFF
}

void loop() {
  sensorValue = analogRead(sensorPin);  // 센서값 읽음
  // 판독된 아날로그 센서값(0~1023)을 0~255 값으로 변환하여 변수에 저장
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);
  // 0~255 범위를 넘어서면 보정하여 변수에 저장. map() 함수 전,후에 사용
  sensorValue = constrain(sensorValue, 0, 255);
  analogWrite(ledPin, sensorValue); // 센서값으로 LED ON, OFF
}

int trigPin = 2;  // 트리거 핀. 2번 핀에 연결
int echoPin = 3;  // 에코 핀. 3번 핀에 연결

void setup() {
  pinMode(trigPin, OUTPUT);   // 트리거 핀. 출력으로 설정
  pinMode(echoPin, INPUT);    // 에코 핀. 입력으로 설정

  Serial.begin(9600);
  Serial.println("HC-SR04. distance measure start!");
  Serial.println();
}

void loop() {
  float duration, cm;

  digitalWrite(trigPin, HIGH);  // 트리거 핀 HIGH 펄스
  delayMicroseconds(10);  // 10 us 지연.
  digitalWrite(trigPin, LOW); // 8 Cycle 초음파 출력

  duration = pulseIn(echoPin, HIGH);   // HIGH가 유지된 시간 반환
  cm = duration / 58.0;   // 거리 = 왕복에 걸린 시간 / 58

  Serial.print("distance : ");
  Serial.print(cm);
  Serial.println("cm");
  delay(1000);
}

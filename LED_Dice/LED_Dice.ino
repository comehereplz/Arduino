int ledPin[7] = {3, 4, 5, 6, 7, 8, 9}; // LED 연결 핀 번호 초기화

int diceData[7][7] = {
  {0, 0, 0, 0, 0, 0, 1},  // 1
  {0, 0, 1, 1, 0, 0, 0},  // 2
  {0, 0, 1, 1, 0, 0, 1},  // 3
  {1, 0, 1, 1, 0, 1, 0},  // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 1, 1, 1, 1, 1, 0},  // 6
  {0, 0, 0, 0, 0, 0, 0}   // LED OFF
};

int pushPin = 2;  // 푸시 버튼 2번 핀에 연결
int ledOff = 6;   // LED OFF. 배열 행 초기

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(ledPin[i], OUTPUT); // 3~9번 핀 출력 설정
    digitalWrite(ledPin[i], LOW); // 3~9번 핀 LED OFF
  }

  pinMode(pushPin, INPUT);  // 푸시 버튼 2번 핀 입력 설정
  randomSeed(analogRead(0));  // 난수 입력 초기화
}

void loop() {
  int randLed = 0;
  int rollcnt = random(10, 20); // 10~19 사이 랜덤 수 저장

  if (digitalRead(pushPin)) { // 푸시 버튼이 눌려지면
    for (int i = 0; i < rollcnt; i++) { // rollcnt 값만큼 반복
      randLed = random(0, 6); // 0~5 사이 랜덤 수 저장
      diceLed(randLed); // 주사위 숫자 호출
      delay(30 + i * 20); // 점점 느려짐
    }

    for (int j = 0; j < 3; j++) { // 세 번 반복
      diceLed(ledOff);  // 주사위 LED OFF
      delay(500); // 500ms 지연
      diceLed(randLed); // randLed 값 LED ON
      delay(500); // 500ms 지연
    }
  }
  delay(100);
}

void diceLed(int ledOn) { // 주사위 값 LED ON
  for (int i = 0; i < 7; i++) {
    digitalWrite(ledPin[i], diceData[ledOn][i]);
  }
}

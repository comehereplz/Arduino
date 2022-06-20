int sirenPin = 3;   // 부저의 +극을 아두이노 보드 3번에 연결

void setup() {
  // tone 함수 사용 시 입출력 모드 설정 필요 없음
}

void loop() {
  for (int siren = 200; siren < 2500; siren += 1) {
    tone(sirenPin, siren, 10);
  }

  for (int siren = 2500; siren > 200; siren -= 1) {
    tone(sirenPin, siren, 10);
  }
}

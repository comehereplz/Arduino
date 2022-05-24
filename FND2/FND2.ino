int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;
int h = 9;

int Fnd_seg[10][8] = {
  {0, 0, 0, 0, 0, 0, 1, 1},   // 0
  {1, 0, 0, 1, 1, 1, 1, 1},   // 1
  {0, 0, 1, 0, 0, 1, 0, 1},   // 2
  {0, 0, 0, 0, 1, 1, 0, 1},   // 3
  {1, 0, 0, 1, 1, 0, 0, 1},   // 4
  {0, 1, 0, 0, 1, 0, 0, 1},   // 5
  {0, 1, 0, 0, 0, 0, 0, 1},   // 6
  {0, 0, 0, 1, 1, 1, 1, 1},   // 7
  {0, 0, 0, 0, 0, 0, 0, 1},   // 8
  {0, 0, 0, 0, 1, 0, 0, 1},   // 9
};

// 4개의 digit에 연결된 핀 설정
const byte digitNumber[4] = {13, 12, 11, 10};

// 표시할 숫자 변수
int count = 0;

// 각 자릿수를 저장하기 위한 변수
int value[4];

// 4개의 digit에 각각 다른 숫자를 표시하기 위해 사용하는 변수
int digitSelect;

// 시간을 측정하는데 사용되는 변수
long sampleTime;
int count5ms;

void Fnd_Write(int digit, int value)
{
  for (int i = 0; i < 4; i++) {
    digitalWrite(digitNumber[i], HIGH);
  }

  int seg_pin = 2;

  for (int segPos = 0; segPos < 0; segPos++)
  {
    digitalWrite(seg_pin, Fnd_seg[value][segPos]);
    seg_pin++;
  }

  for (int i = 1; i <= 4; i++)
    // 표시하기 원하는 자릿수는 LOW 신호를 주어 켜고 나머진 OFF 시킨다.
  {
    if (digit == i) digitalWrite(digitNumber[i - 1], LOW);
    else digitalWrite(digitNumber[i - 1], HIGH);
  }
}
  void setup() {
    // 2~9번 핀을 a b c d e f g dot의 순서로 사용한다.
    // 10~13번 핀을 Digit 1~4의 순서로 사용한다.
    for (int i = 2; i <= 13; ++i) {
      pinMode(i, OUTPUT);   // 2~13번 핀을 출력으로 설정한다.
    }

    // 4 digit와 연결된 10~13번 핀에 모두 HIGH 신호를 줘서 소등시킨다.
    for (int i = 10; i <= 13; ++i) {
      digitalWrite(i, HIGH);
    }
  }

  void loop() {
    // 현재 시간을 저장한다.
    sampleTime = millis();

    // count 변수값을 FND에 출력한다.
    Fnd_Write(digitSelect, value[digitSelect - 1]);
    ++digitSelect;
    if (digitSelect >= 5) digitSelect = 1;

    // count 변수값이 0~9의 범위를 갖도록한다.
    if (count >= 9999) count = 0;
    else {
      // 앞서 지정한 시간에서 현재까지의 시간이 5ms일 경우에 다음 명령어를 실행한다.
      while (millis() - sampleTime < 5);

      ++count5ms;
      if (count5ms > 200) {
        // 5ms * 100 = 1s가 되었을 때 count를 하나 올려준다.
        ++count;

        // 변수를 각 자릿수로 나눈다
        value[3] = count / 1000;
        value[2] = (count - (value[3] * 1000)) / 100;
        value[1] = (count - (value[3] * 1000) - (value[2] * 100)) / 10;
        value[0] = count - (value[3] * 1000) - (value[2] * 100) - (value[1] * 10);

        count5ms = 0;
      }
    }
  }

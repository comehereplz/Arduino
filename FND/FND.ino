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
  {0, 0, 0, 0, 0, 0, 0, 1}    // 8
  {0, 0, 0, 0, 1, 0, 0, 1}    // 9
};

void setup() {
  pinMode(a, OUTPUT);   
  pinMode(b, OUTPUT);   
  pinMode(c, OUTPUT);   
  pinMode(d, OUTPUT);  
  pinMode(e, OUTPUT);   
  pinMode(f, OUTPUT);   
  pinMode(g, OUTPUT);
  pinMode(h, OUTPUT);  
}

void Fnd_Write(int row)
{
    int seg_Pin = 2;

  for(int segPos = 0; segPos < 8; segPos++) // 세그먼트 a~h까지
  {
    digitalWrite(seg_Pin, Fnd_seg[row][segPos]);
    seg_Pin++;
  }
}

void loop() {
  for(int count = 0; count < 10; count++) // 숫자 0에서 9까지
  {
    Fnd_Write(count);     // Fnd_Write 함수 호출
    delay(500);
  }
}

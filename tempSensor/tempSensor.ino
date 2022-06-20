int tmpPin = A0;  // 온도 센서 신호 출력 핀. 아두이노 보드 A0에 연결

void setup() {
  Serial.begin(9600);
  Serial.println("start measure of temparture");
}

void loop() {
  int tempValue = analogRead(tmpPin);
  float tempVolt = tempValue * 5.0 / 1024.0;  
  float celsiusTemp = (tempVolt - 0.5) * 100;
  float fahrenheitTemp = (celsiusTemp * 9.0 / 5.0) + 32.0;  // (celsiusTemp * 1.8) + 32.0

  Serial.print("Celsius : ");
  Serial.println(celsiusTemp);

  Serial.print("Fahrenheit : ");
  Serial.println(fahrenheitTemp);
  Serial.println();
  delay(3000);
}

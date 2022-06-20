int SW = 2;
int VRX = A1;
int VRY = A0;

void setup() {
  Serial.begin(9600);
  pinMode(SW, INPUT_PULLUP);
}

void loop() {
  Serial.print("VRX = ");
  Serial.print(analogRead(VRX));
  Serial.print(" / ");
  Serial.print("VRY = ");
  Serial.print(analogRead(VRY));
  Serial.print(" / ");
  Serial.print("SW = ");
  Serial.println(digitalRead(SW));
  delay(500);
}

int ldrIn = 0;
int flag = 2;

void setup() {
  Serial.begin(9600);
  //pinMode(A0, INPUT);

}

void loop() {
  int ldrIn = analogRead(A0);
  if(ldrIn < 100) {
    digitalWrite(flag, HIGH);
  }
  else {
    digitalWrite(flag, LOW);
  }
  Serial.println(ldrIn);
  delay(1000);

}

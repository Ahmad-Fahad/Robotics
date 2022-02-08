int ldrIn = 0;

void setup() {
  Serial.begin(9600);
  //pinMode(A0, INPUT);

}

void loop() {
  int ldrIn = analogRead(A0);
  Serial.println(ldrIn);
  delay(1000);

}

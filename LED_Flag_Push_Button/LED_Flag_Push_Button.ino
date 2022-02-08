int button = 3;
int led = 13;

void setup() {
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);

}

void loop() {
  int flag = digitalRead(button);
  if(flag != 0) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }

}

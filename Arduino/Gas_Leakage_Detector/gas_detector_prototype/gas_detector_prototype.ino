const int green  = 2;
const int yellow = 3;
const int red    = 4;
const int beep   = 5;
const int gas_low = 200;
const int gas_normal = 200;
const int gas_risky = 200;
const int gas_danger = 200;

int gas = 0;
void setup() {
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  gas = analogRead(A0);
  Serial.println("Gas Data");
  Serial.println(gas);
  //tone(beep, 750);
  //delay(500);
  if(gas >= 200 && gas < 300) {
    digitalWrite(green, HIGH); 
  }
  else if(gas >= 300 && gas < 350) {
    digitalWrite(yellow, HIGH);
  }
  else if(gas >= 350) {
    digitalWrite(red, HIGH);
  }
  else if(gas >= 350) {
    digitalWrite(red, HIGH);
    digitalWrite(beep, HIGH);
  }
  else {
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    
  }
//noTone(beep);
  delay(500);


}

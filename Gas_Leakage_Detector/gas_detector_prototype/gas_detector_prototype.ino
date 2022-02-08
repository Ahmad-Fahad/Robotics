const int green  = 2;
const int yellow = 3;
const int red    = 4;
const int beep   = 5;
const int beep_frequency = 500;
const int beep_Xtrm_frequency = 700;
const int gas_data = A0;
const int gas_low = 200;
const int gas_normal = 250;
const int gas_risky = 300;
const int gas_danger = 350;
const int gas_Xtrm_danger = 400;
const int delay_ms = 500;

int gas = 0;
void setup() {
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  gas = analogRead(gas_data);
  Serial.println("Gas Data : ");
  Serial.println(gas);
  if(gas >= gas_low && gas < gas_normal) {
    digitalWrite(green, HIGH); 
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    noTone(beep);
  }
  else if(gas >= gas_normal && gas < gas_risky) {
    digitalWrite(yellow, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(red, LOW);
    noTone(beep);
  }
  else if(gas >= gas_danger && gas < gas_Xtrm_danger) {
    digitalWrite(red, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);
    tone(beep, beep_frequency);
  }
  else if(gas >= gas_Xtrm_danger) {
    digitalWrite(red, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);
    tone(beep, beep_Xtrm_frequency);
  }
  else {
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    noTone(beep);
  }
  delay(delay_ms);
}

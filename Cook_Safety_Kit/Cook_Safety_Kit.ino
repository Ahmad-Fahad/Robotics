const int green  = 2;
const int yellow = 3;
const int red    = 4;
const int beep   = 5;
const int flame_pin = 6;
const int flame_flag_pin = 7;
const int beep_frequency = 500;
const int beep_Xtrm_frequency = 700;
const int beep_flame_freq = 800;
const int gas_data = A0;
const int gas_low = 200;
const int gas_normal = 250;
const int gas_risky = 300;
const int gas_danger = 350;
const int gas_Xtrm_danger = 400;
const int delay_ms = 500;
int gas = 0;
void setup() {
  pinMode(flame_pin, INPUT);
  pinMode(flame_flag_pin, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  Serial.begin(9600);
}

void loop() {
 
  gas = analogRead(gas_data);
  gas_leakage_detector(gas);
 
  int is_fire = 1;
  is_fire = digitalRead(flame_pin);
  flame_indicaor(is_fire);
  
  delay(delay_ms);

}

void gas_leakage_detector(int gas) {
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
    delay(delay_ms);
  }
  else if(gas >= gas_Xtrm_danger) {
    digitalWrite(red, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);
    tone(beep, beep_Xtrm_frequency);
    delay(delay_ms);
  }
  else {
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    noTone(beep);
  }
}

void flame_indicaor(int is_fire) {
  Serial.println(is_fire);
  if(is_fire == LOW){
    digitalWrite(flame_flag_pin, HIGH);
    tone(beep, beep_flame_freq);
    delay(500);
  }
  else {
    digitalWrite(flame_flag_pin, LOW);
    noTone(beep);
    //delay(500);
  }
}


 

const int flame_pin = 6;
const int flame_flag_pin = 7;
const int beep_flame = 5;
const int beep_flame_freq = 700;

void setup() {
  pinMode(flame_pin, INPUT);
  pinMode(flame_flag_pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int is_fire = 1;
  is_fire = digitalRead(flame_pin);
  Serial.println(is_fire);
  if(is_fire == LOW){
    digitalWrite(flame_flag_pin, HIGH);
    tone(beep_flame, beep_flame_freq);
    delay(500);
  }
  else {
    digitalWrite(flame_flag_pin, LOW);
    noTone(beep_flame);
    delay(500);
  }
}

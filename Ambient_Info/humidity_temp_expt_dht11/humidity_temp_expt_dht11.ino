#include<DHT.h>
#define DHTPIN A1
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  dht.begin();
  Serial.begin(9600);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.println();
  Serial.print("Humidity = ");
  Serial.print(h);
  Serial.println("%");
  Serial.println();
  Serial.print("Temperature = ");
  Serial.print(t);
  Serial.println(" *C");
  delay(5000);

}

#include "DHT.h"
#define DHTPIN 21
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
void setup() {
  Serial.begin(9600); // monitor window for checking data
  Serial1.begin(9600); //bluetooth window for sending data
  pinMode(DHTPIN, INPUT); //set pin mode as input
  dht.begin(); // starts dht sensor
}

void loop() {
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    Serial.print(F("1201 Humidity "));
    Serial.print(h);
    Serial.print(F(" % Temperature "));
    Serial.print(t);
    Serial.println(F(" C"));
    delay(1000);
    Serial1.print(F("1201 Humidity "));
    Serial1.print(h);
    Serial1.print(F(" % Temperature "));
    Serial1.print(t);
    Serial1.println(F(" C"));
    delay(1000);
  }

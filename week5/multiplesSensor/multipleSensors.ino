#include "DHT.h"
#define DHTPIN 21      // Digital pin connected to the DHT sensor
#define SOILPIN 12      // Digital pin connected to the SOIL sensor
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  // put your setup code here, to run once:
  pinMode(SOILPIN, INPUT);
  pinMode(DHTPIN, INPUT);
  dht.begin();
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  callHumi();
  delay(5000);
  callSoil();
  delay(5000);
}

void callHumi(){
  float h = dht.readTemperature();
  Serial1.print("Temp : ");
  Serial1.println(h);
  Serial.print("Temp : ");
  Serial.println(h);
}

void callSoil(){
  int t = analogRead(SOILPIN);
  Serial1.print("Soil : ");
  Serial1.println(t);
  Serial.print("Soil : ");
  Serial.println(t);
  
}

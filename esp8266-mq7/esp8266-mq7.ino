#include <ESP8266WiFi.h>

const char *ssid = "wifi";    
const char *password = "password";

const int analogPin = A0;

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  
  Serial.println("\nConnected to WiFi");
}

void loop() {
  int sensorValue = analogRead(analogPin);

  Serial.print("MQ7 Sensor Value: ");
  Serial.println(sensorValue);

  delay(1000);
}

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "Your_Blynk_Auth_Token";
char ssid[] = "Your_WiFi_Name";
char pass[] = "Your_WiFi_Password";

int relayPin = D1;
void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH); 
  Blynk.begin(auth, ssid, pass);
}

BLYNK_WRITE(V1) {
  int value = param.asInt();
  if (value == 1) {
    digitalWrite(relayPin, LOW);  
  } else {
    digitalWrite(relayPin, HIGH); 
  }
}

void loop() {
  Blynk.run();
}

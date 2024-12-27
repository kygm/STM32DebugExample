#define LED_BUILTIN PC13

#include <Arduino.h>

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
}

int delayMs = 1000;

void loop() {

  if(delayMs < 100)
  {
    delayMs = 1000;
  }

  digitalWrite(LED_BUILTIN, HIGH); 
  delay(delayMs); 
  digitalWrite(LED_BUILTIN, LOW);  
  delay(delayMs);

  delayMs -= 50;
}
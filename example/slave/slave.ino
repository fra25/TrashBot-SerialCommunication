#include <Serial.h>

// Al momento facciamo solo accendere dei led

String data;

void lampeggio(int pinLed = 1) {
  digitalWrite(pinLed, HIGH);
  delay(200);
  digitalWrite(pinLed, LOW);
}

void setup() {
  Serial.begin(9600);
  pinMode(1, OUTPUT);
  digitalWrite(1, LOW);
}

void loop() {
  data = Serial.readString()
  if (data == "1") {
    lampeggio();
  }
  else if (data == "2") {
    lampeggio();
    lampeggio();
  }
}

#include <Wire.h>

void setup() {
  Serial.begin(9600);
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
  pinMode(13, OUTPUT);
}

void loop() {
  delay(100);
}

void receiveEvent(int howMany) {
  int x = Wire.read();

  if(x == 0) {
    digitalWrite(13, LOW);
  }
  else {
    digitalWrite(13, HIGH);
  }
}

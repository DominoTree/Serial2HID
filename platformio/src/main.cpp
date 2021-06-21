#include <Arduino.h>
#include <Keyboard.h>
#include <Mouse.h>

int incomingByte = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(1200, SERIAL_7N1);  //serial mice operate at 1200 baud
  while(!Serial);
  SerialUSB.begin(9600);
  while(!SerialUSB);
  Keyboard.begin();
  Mouse.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    // say what you got:
    SerialUSB.print("I received: ");
    SerialUSB.println(incomingByte, DEC);
  }
}
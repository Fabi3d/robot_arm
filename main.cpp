#include <Arduino.h>
#include "farberkennung.h"
#include "move_servos.h"




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

   if (tcs.begin()) {

 Serial.println("Sensor gefunden");
 } else {

   Serial.println("TCS34725 nicht gefunden ... Ablauf gestoppt!");
// while (1);
 }

goHome();

}



void loop() {
  // put your main code here, to run repeatedly:
  //readColor();
  moveToPosition(150, 20, 30, 5, 250);
  Serial.println(servo1_pos);

  while(1);
  //stopping
while(1);
}

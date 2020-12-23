/*
 * author: Fabian Klotz
 * date of lastest change: 01.12.2020
 * lastest changes: added neopixels to the robot arm to show visualy the color of the Lego part
*/
#include <Arduino.h>                          //include the Arduino framework and all necessary librarys
#include "farberkennung.h"
#include "move_servos.h"
#include "neopixels.h"



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);                       //start a Serial communication
  servo1.attach(5);                         //the Servos are attached to the pins 5,7,9 and 11
  servo2.attach(7);
  servo3.attach(9);
  gripper.attach(11);
  strip.begin();                  //start the neopixels
    strip.setBrightness(250);     //set to maximum brightness
    strip.show(); // Initialize all pixels to 'off'
   if (tcs.begin()) {                       //start the colorsensor

 Serial.println("Sensor gefunden");
 } else {

   Serial.println("TCS34725 nicht gefunden ... Ablauf gestoppt!");
// while (1);
 }

goHome();                               //move to the home position
delay(500);
Initialize();


}



void loop() {
  // put your main code here, to run repeatedly:
  if(readColor() == "red"){
    redLight();
    take();
    redMovement();
  }
  if(readColor() == "blue"){
    blueLight();
    take();
    blueMovement();
  }
  if(readColor() == "green"){
    greenLight();
    take();
    greenMovement();
  }
  if(readColor() == "yellow"){
    yellowLight();
    take();
    yellowMovement();
  }


}

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
delay(2000);

}



void loop() {
  // put your main code here, to run repeatedly:
        //example movement: moveToPosition(servo1, servo2, servo3, gripper, delay)
  readColor();                          //call the method readColor() to get the tcs measurement


  if(gruen == true)                     //movements for each color
  {
    greenLight();
    take();
    greenMovement();
    gruen = false;

  }

  if(rot == true)
  {
    redLight();
    take();
    redMovement();
    rot = false;
  }

  if (gelb == true)
  {
    yellowLight();
    take();
    yellowMovement();
    gelb = false;
  }

  if(blau == true)
  {
    blueLight();
    take();
    blueMovement();
    blau = false;
  }


}

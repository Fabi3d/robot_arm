#include <Wire.h>
#include <Adafruit_TCS34725.h>

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_154MS, TCS34725_GAIN_4X);
bool rot = false;
bool blau = false;
bool gelb = false;
bool gruen = false;

void readColor()
{
  uint16_t clearcol, red, green, blue;
 float average, r, g, b;
 delay(100); // Farbmessung dauert c. 50ms
 tcs.getRawData(&red, &green, &blue, &clearcol);


 // Durchschnitt von RGB ermitteln
 average = (red+green+blue)/3;
 // Farbwerte durch Durchschnitt,
 // alle Werte bewegen sich jetzt rund um 1
 r = red/average;
 g = green/average;
 b = blue/average;


 Serial.print("\tClear:"); Serial.print(clearcol);
 Serial.print("\tRed:"); Serial.print(r);
 Serial.print("\tGreen:"); Serial.print(g);
 Serial.print("\tBlue:"); Serial.println(b);



 if(r>=1.15 && g<0.85 && b<1)
 {
  Serial.println("rot");
  rot = true;
 }

 if(r <0.6 && g<1.1 && b>1.4)
 {
  Serial.println("blau");
  blau = true;
 }
 if(r > 1.1 && g>1 && b<0.75)
 {
  Serial.println("gelb");
  gelb= true;
 }
 if(r<0.7 && g>=1.1 && b>1.15)
 {
  Serial.println("grün");
  gruen = true;
 }


}

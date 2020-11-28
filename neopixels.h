#include <Adafruit_NeoPixel.h>

#define PIN 4
Adafruit_NeoPixel strip = Adafruit_NeoPixel(7, PIN, NEO_GRB + NEO_KHZ800);

void greenLight()
{
  for(int i = 0; i<=6; i++)
  {
    strip.setPixelColor(i, strip.Color(0, 250, 0));
    delay(90);
    strip.show();
  }
  strip.clear();
  for(int i = 0; i<=6; i++)
  {
    strip.setPixelColor(i, strip.Color(0, 250, 0));
    delay(90);
    strip.show();
  }
  strip.clear();
    strip.show();
}

void redLight()
{
  for(int i = 0; i<=6; i++)
  {
    strip.setPixelColor(i, strip.Color(250, 0, 0));
    delay(90);
    strip.show();
  }
  strip.clear();
  for(int i = 0; i<=6; i++)
  {
    strip.setPixelColor(i, strip.Color(250, 0, 0));
    delay(90);
    strip.show();
  }
  strip.clear();
    strip.show();
}
void blueLight()
{
  for(int i = 0; i<=6; i++)
  {
    strip.setPixelColor(i, strip.Color(0, 0, 250));
    delay(90);
    strip.show();
  }
  strip.clear();
  for(int i = 0; i<=6; i++)
  {
    strip.setPixelColor(i, strip.Color(0, 0, 250));
    delay(90);
    strip.show();
  }
  strip.clear();
  strip.show();
}
void yellowLight()
{
  for(int i = 0; i<=6; i++)
  {
    strip.setPixelColor(i, strip.Color(245, 250, 0));
    delay(90);
    strip.show();
  }
  strip.clear();
  for(int i = 0; i<=6; i++)
  {
    strip.setPixelColor(i, strip.Color(245, 255, 0));
    delay(90);
    strip.show();
  }
  strip.clear();
    strip.show();
}

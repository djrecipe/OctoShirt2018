#include <Adafruit_NeoPixel.h>

#define PIN 5
#define COUNT 1

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(COUNT, PIN, NEO_GRB + NEO_KHZ800);

int currentDelay = 500; // delay for half a second

void setup()
{
  pixels.begin(); // This initializes the NeoPixel library.
  return;
}

void loop()
{
  pixels.setPixelColor(0, pixels.Color(150,0,0));
  pixels.show();
  
  delay(currentDelay);
}

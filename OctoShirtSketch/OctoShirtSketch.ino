#define PIN 5
#define COUNT 4
#define WHEEL_SIZE 384 // wheel sizes > 384 will cause gaps in the rainbow, while < 384 will cause truncated rainbow

#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(COUNT, PIN, NEO_GRB + NEO_KHZ800);

int currentDelay = 10;
int currentColorIndex = 1;
int currentColorIncrement = 1;
int currentlyIncrementingColor = true;

void setup()
{
  pixels.begin(); // This initializes the NeoPixel library.
  return;
}

void loop()
{
  uint32_t color = GetColor(currentColorIndex);
  for(int i=0; i<COUNT; i++)
  {
    pixels.setPixelColor(i, color); 
  }
  pixels.show();
  
  IncrementColorIndex();
  
  delay(currentDelay);
}


/// <summary>
/// Retrieve a color
/// </summary>
/// <param name=seed>Optional color seed</param>
/// <returns>An unsigned integer representing an RGB color value</returns>
uint32_t GetColor(uint16_t seed)
{
  float ratio = ((float)seed)/((float)WHEEL_SIZE);
  uint32_t color = pixels.Color(ratio * 200.0, 1, 1);
  return color;
}



/// <summary>
/// Advance the current color index according to the current settings
/// </summary>
void IncrementColorIndex()
{
  // determine color index direction
  if(currentColorIndex >= WHEEL_SIZE)
    currentlyIncrementingColor = false;
  else if(currentColorIndex <=0)
    currentlyIncrementingColor = true;
  // increment or decrement color index
  if(currentlyIncrementingColor)
    currentColorIndex += currentColorIncrement;
  else
    currentColorIndex -= currentColorIncrement;
  return;
}

 /**
 * tcomThings by tognella.com
 * Arduino Nano - tcomNeopixelFirepit
 * v. 1.0
 * Copyright (C) 2021 Patrick Tognella
 * https://tognella.com
 * IDE: 1.8.15 or higher
 * Board: Arduino Nano
 *
 * Libraries
 * NeoPixel: https://github.com/adafruit/Adafruit_NeoPixel
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <Adafruit_NeoPixel.h>

// data pin
#define PIN 6
// led count
#define CNT 12

// Initialize NeoPixel Ring from Adfruit
Adafruit_NeoPixel strip = Adafruit_NeoPixel(CNT, PIN, NEO_RGBW);

//Define fire colors inkl. off 
uint32_t fire_color0   = strip.Color ( 50,  226,  5,0);
uint32_t fire_color1   = strip.Color ( 25,  255,  0,0);
uint32_t fire_color2   = strip.Color ( 10,  250,  10,10);
uint32_t fire_color3   = strip.Color ( 0,  0,  0,128);
uint32_t fire_color4   = strip.Color (  0,  0,  0, 0);

///
/// Setup
///
void setup()
{
strip.begin();
strip.show(); // Initialize all pixels to 'off'
}

///
/// Main loop
///
void loop()
{
  for(int i=0;i<CNT;i++)
  {
    switch (random(5))
    {
      case 0:
        strip.setPixelColor(i, fire_color0);
        break;
        
      case 1:
        strip.setPixelColor(i, fire_color1);
        break;

      case 2:
        strip.setPixelColor(i, fire_color2);
        break;

      case 3:
        strip.setPixelColor(i, fire_color3);
        break;
        
      case 4:
        strip.setPixelColor(i, fire_color4  );
        break;        
    }
    
  }
  strip.show();

delay(random(50,250));
}

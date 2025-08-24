#include <Arduino.h>
#include "SuperBlink.h"
#include "Adafruit_NeoPixel.h"

RgbLED led(7, NEO_RGB); // Assume that one neopixel is connected to pin 7.
SuperBlink blink(led);

void setup() 
{
    // Configure LED to blink according to a 32-bit binary pattern
    // The duration of each bit is 200 ms.
    blink.set32BitPattern(0b10101010111100001111000011110000, 200);
}

void loop()
{
    blink.loop();
}

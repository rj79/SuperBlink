#include <Arduino.h>
#include "SuperBlink.h"

SuperBlink led(LED_BUILTIN);

void setup() 
{
    // Configure LED to blink according to a 32-bit binary pattern
    // The duration of each bit is 200 ms.
    led.setBitPattern(0b10101010111100001111000011110000, 200);
}

void loop()
{
    led.loop();
}

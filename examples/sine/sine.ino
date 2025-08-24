#include <Arduino.h>
#include "SuperBlink.h"

StandardLED led(LED_BUILTIN);
SuperBlink blink(led);

void setup() 
{
    // Configure LED to pulsate at a rate of 1/5 Hz.
    blink.setSine(1.0/5);
}

void loop()
{
    blink.loop();
}

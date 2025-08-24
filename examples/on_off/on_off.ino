#include <Arduino.h>
#include "SuperBlink.h"

StandardLED led(LED_BUILTIN);
SuperBlink blink(led);

void setup() 
{
    // Configure LED to be on for 250 ms, then off for 750 ms repeatedly.
    blink.setPattern(250, 750);
}

void loop()
{
    blink.loop();
}

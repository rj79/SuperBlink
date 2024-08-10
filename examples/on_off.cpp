#include <Arduino.h>
#include "SuperBlink.h"

SuperBlink led(LED_BUILTIN);

void setup() 
{
    // Configure LED to be on for 250 ms, then off for 750 ms repeatedly.
    led.setPattern(250, 750);
}

void loop()
{
    led.loop();
}

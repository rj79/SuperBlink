#include <Arduino.h>
#include "SuperBlink.h"

SuperBlink led(LED_BUILTIN);

void setup() 
{
    // Configure LED to pulsate at a rate of 1/5 Hz.
    led.setSine(1.0/5);
}

void loop()
{
    led.loop();
}

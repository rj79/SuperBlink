#include <Arduino.h>
#include "SuperBlink.h"

StandardLED led(LED_BUILTIN);
SuperBlink blink(led);

void setup() 
{
    // The LED is off by default. It can be turned on and off manually.
    blink.on();
}

void loop()
{
    // In this case, where the LED remains on, it is really not necessary to
    // call led.loop().
    blink.loop();
}

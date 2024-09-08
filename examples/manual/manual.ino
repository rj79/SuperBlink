#include <Arduino.h>
#include "SuperBlink.h"

SuperBlink led(LED_BUILTIN);

void setup() 
{
    // The LED is off by default. It can be turned on and off manually.
    led.on();
}

void loop()
{
    // In this case, where the LED remains on, it is really not necessary to
    // call led.loop().
    led.loop();
}

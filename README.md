# About
SuperBlink is a library for creating LED blinking patterns.
It can be useful to indicate various states to the user.

# Usage
There are three main modes of operation:

1. **On/Off**: In this mode the LED is on for a specified number of 
milliseconds, then off for another specified milliseconds. Set an on/off 
pattern by calling:
        setPattern(\<on millis\>, \<off millis\>);
2. **Bit pattern**: In this mode the LED is lit according to a binary pattern
by calling one of:
        set32BitPattern(\<32-bit pattern\>, \<bit duration millis\>);
        set16BitPattern(\<16-bit pattern\>, \<bit duration millis\>);
        set8BitPattern(\<8-bit pattern\>, \<bit duration millis\>);
The pattern runs left-to-right, i.e. with the most significant bits first.
3. **Sine wave**: In this mode the LED will pulsate at the given frequency. 
Note that the LED output pin must be supporting PWM.


It is also possible to disable patterns and set the LED in a static mode by calling on() or off(). The LED is off by default.


On/Off example
==============
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

Bit pattern example
===================
    #include <Arduino.h>
    #include "SuperBlink.h"
    
    SuperBlink led(LED_BUILTIN);
    
    void setup() 
    {
        // Configure LED to blink according to a 32-bit binary pattern
        // The duration of each bit is 200 ms.
        led.set32BitPattern(0b10101010111100001111000011110000, 200);
    }
    
    void loop()
    {
        led.loop();
    }

Sine wave example
=================
    #include <Arduino.h>
    #include "SuperBlink.h"

    SuperBlink led(LED_BUILTIN);

    void setup() 
    {
        // Configure LED to pulsate at a rate of 5 Hz.
        led.setSine(5);
    }

    void loop()
    {
        led.loop();
    }

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

# Single color LEDs and RGB LEDs
The library can use both single color standard LEDs as well as NeoPixel-style LEDs.
To use a standard LED, first instantiate a StandardLED object, and pass it to the SuperBlink constructor.

    StandardLED led(LED_BUILTIN);
    SuperBlink blink(led);

Calling setColor() on a StandardLED object has no effect.

To use a RGB LED, first instantiate a RgbLED object and pass it to the SuperBlink constructor.

    RgbLED rgb(RGB_POWER, RGB_DATA);
    SuperBlink blink(rgb);


On/Off example
==============
    #include <Arduino.h>
    #include "SuperBlink.h"
    
    BuiltinLED led(LED_BUILTIN);
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

Bit pattern example
===================
    #include <Arduino.h>
    #include "SuperBlink.h"
    
    BuiltinLED led(LED_BUILTIN);
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

Sine wave example
=================
    #include <Arduino.h>
    #include "SuperBlink.h"

    BuiltinLED led(LED_BUILTIN);
    SuperBlink blink(led);

    void setup() 
    {
        // Configure LED to pulsate at a rate of 5 Hz.
        blink.setSine(5);
    }

    void loop()
    {
        blink.loop();
    }

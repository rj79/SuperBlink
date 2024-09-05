#include <Arduino.h>
#include "SuperBlink.h"

uint32_t reverse_bits(uint32_t value)
{
    uint32_t result = 0;
    for (int8_t i = 31; i >= 0; --i) {
        result = result | ((value & 1) << i);
        value = value >> 1;
    }
    return result;
}

SuperBlink::SuperBlink(uint8_t pin, bool inverse) :
    Pin(pin),
    Inverse(inverse),
    Mode(STATIC),
    On(false),
    OnTime(1000),
    OffTime(1000),
    LastChange(0),
    BitPattern(0),
    BitTime(0),
    BitPos(0)
{
    pinMode(Pin, OUTPUT);
    off();
}

void SuperBlink::setPattern(uint32_t onTimeMS, uint32_t offTimeMS)
{
    Mode = ON_OFF;
    OnTime = onTimeMS;
    OffTime = offTimeMS;
    On = true;
    update(millis());
}

void SuperBlink::set32BitPattern(uint32_t pattern, uint32_t bitTimeMS)
{
    Mode = BIT_PATTERN;
    BitCount = 32;
    BitPattern = reverse_bits(pattern);
    BitTime = bitTimeMS;
    BitPos = 0;
    On = BitPattern & 1;
    update(millis());
}

void SuperBlink::set16BitPattern(uint16_t pattern, uint32_t bitTimeMS)
{
    Mode = BIT_PATTERN;
    BitCount = 16;
    BitPattern = reverse_bits((uint32_t)pattern) >> 16;
    BitTime = bitTimeMS;
    BitPos = 0;
    On = BitPattern & 1;
    update(millis());
}

void SuperBlink::set8BitPattern(uint8_t pattern, uint32_t bitTimeMS)
{
    Mode = BIT_PATTERN;
    BitCount = 8;
    BitPattern = reverse_bits((uint32_t)pattern) >> 24;
    BitTime = bitTimeMS;
    BitPos = 0;
    On = BitPattern & 1;
    update(millis());
}

void SuperBlink::on()
{
    Mode = STATIC;
    On = true;
    update(millis());
}

void SuperBlink::off()
{
    Mode = STATIC;
    On = false;
    update(millis());
}

void SuperBlink::loop()
{
    unsigned long now = millis();
    if (Mode == ON_OFF) {        
        if (On) {
            if (now - LastChange >= OnTime) {
                On = false;
                update(now);
            }
        }
        else {
            if (now - LastChange >= OffTime) {
                On = true;
                update(now);
            }
        }
    }
    else if (Mode == BIT_PATTERN) {
        if (now - LastChange >= BitTime) {
            BitPos = (BitPos + 1) & (BitCount - 1);
            On = (BitPattern >> BitPos) & 1;
            update(now);
        }
    }
}

void SuperBlink::update(unsigned long time)
{
    digitalWrite(Pin, On ? (Inverse ? LOW : HIGH) : (Inverse ? HIGH : LOW));
    LastChange = time;
}

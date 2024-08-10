#ifndef SUPERBLINK_H
#define SUPERBLINK_H

#include <stdint.h>


/**
 * A class to control LED blinking
 */
class SuperBlink 
{
public:
    /**
     * Constructor.
     * @param pin The output pin connected to the LED.
     * @param inverse If inverse is true, it is assumed that the LED will light
     * when the output is set low. The default is false meaning that it is 
     * assumed that the LED will light when the output is set high.
    */
    SuperBlink(uint8_t pin, bool inverse=false);

    /**
     * Set the LED in alternating on/off mode.
     * @param onTimeMS The number of ms the LED will be on.
     * @param offTimeMS The number of ms the LED will be off.
     */
    void setPattern(uint32_t onTimeMS, uint32_t offTimeMS);

    /**
     * Set the LED in binary pattern mode. The LED will blink according to the 
     * 32-bit pattern supplied. For easiest visualization, use binary prefix,
     * e.g. 0b10101010111100001111000011110000. The pattern is executed from 
     * left to right, with the most significant bit first.
     * @param pattern The pattern to use.
     * @param bitTimeMS The duration in ms of each bit.
     */
    void setBitPattern(uint32_t pattern, uint32_t bitTimeMS);

    /**
     * Turn off the LED.
     */
    void off();

    /**
     * Turn on the LED.
     */
    void on();

    /**
     * Call repeatedly in order to execute the chosen pattern.
     */
    void loop();

private:
    enum EMode
    {
        STATIC = 0,
        ON_OFF = 1,
        BIT_PATTERN = 2,
    };
    
    
    uint8_t Pin;
    bool Inverse;

    EMode Mode;
    bool On;
    uint16_t OnTime;
    uint16_t OffTime;
    uint32_t LastChange;
    uint32_t BitPattern;
    uint32_t BitTime;
    uint32_t BitPos;
    

    void update(unsigned long time);
};

#endif

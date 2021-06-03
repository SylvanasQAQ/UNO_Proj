#ifndef BlinkLib_H
#define BlinkLib_H

#include <Arduino.h>

class BlinkLib{
    public:
    static const bool ON = true;
    static const bool OFF = false;

    /**
     * func: BlinkLib
     * para: void
     * ret:  void
     * desc: *default constructor*, set the pin number to 3
    */
    BlinkLib();

    /**
     * func: BlinkLib
     * para: @int pin
     * ret:  void
     * desc: *constructor*, set the pin number to `pin`
    */
    BlinkLib(int pin);

    /**
     * func: blink_1s
     * para: @bool flag
     * ret:  void
     * desc: enable/disable blinking with 1s duration
    */
    void blink_1s(bool flag);

    /**
     * func: blink
     * para: @bool flag
     * para: @int blinkLength
     * ret:  void
     * desc: enable/disable blinking with duration defined by blinkLength
    */
    void blink(bool flag, int blinkLength);

    /**
     * func: blink
     * para: @bool flag
     * para: @int blinkLength
     * para: @int blinkLoops
     * ret:  void
     * desc: enable/disable blinking with duration defined by `blinkLength`
     *       and stop after `blinkLoops` rounds
    */
    void blink(bool flag, int blinkLength, int blinkLoops);


    /**
     * func: blink_breathing
     * para: @bool flag
     * ret:  void
     * desc: enable/disable blinking with breathing style
    */
    void blink_breathing(bool flag);

    private:
        uint8_t pinNum;
};

#endif
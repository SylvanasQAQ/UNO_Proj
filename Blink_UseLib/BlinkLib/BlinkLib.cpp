#include <BlinkLib.h>



BlinkLib::BlinkLib()
{
    pinNum = 3;
    pinMode(pinNum, OUTPUT);
}



BlinkLib::BlinkLib(int pin)
{
    pinMode(pin, OUTPUT);
    pinNum = pin;
}



void BlinkLib::blink_1s(bool flag)
{
    if (flag == true)
    {
        digitalWrite(pinNum, HIGH);
        delay(1000);
        digitalWrite(pinNum, LOW);
        delay(1000);
    }
    else
        digitalWrite(pinNum, LOW);
}



void BlinkLib::blink(bool flag, int blinkLength)
{
    if (blinkLength < 0)
        return;
    if (flag == true)
    {
        digitalWrite(pinNum, HIGH);
        delay(blinkLength);
        digitalWrite(pinNum, LOW);
        delay(blinkLength);
    }
    else
        digitalWrite(pinNum, LOW);
}



void BlinkLib::blink(bool flag, int blinkLength, int blinkLoops)
{
    if (blinkLength < 0)
        return;
    if (flag == true)
    {
        for (int i = 0; i < blinkLoops; i++)
        {
            digitalWrite(pinNum, HIGH);
            delay(blinkLength);
            digitalWrite(pinNum, LOW);
            delay(blinkLength);
        }
    }
    else
        digitalWrite(pinNum, LOW);
}



void BlinkLib::blink_breathing(bool flag)
{
    if (flag == true)
    {
        for(int i = 0; i < 256; i++){
            analogWrite(pinNum, i);
            delay(1000/100);
        }
        for(int i = 255; i > -1; i--){
            analogWrite(pinNum, i);
            delay(1000/100);
        }
    }
    else
        digitalWrite(pinNum, LOW);
}
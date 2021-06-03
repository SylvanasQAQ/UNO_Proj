#include <BlinkLib.h>

// declare pin instance
BlinkLib pin (3);
void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  // blinking every 1s
  //pin.blink_1s(BlinkLib::ON);

  // blinking every 0.5s
  //pin.blink(BlinkLib::ON, 500);

  // blinking every 0.5 for 3 times
  //pin.blink(BlinkLib::ON, 500, 3);

  // 呼吸灯
  pin.blink_breathing(BlinkLib::ON);
  
}

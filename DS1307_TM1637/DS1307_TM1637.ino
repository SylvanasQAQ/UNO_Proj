// DS1307 & TM1637 7-segment with Arduino
#include "TM1637.h"
#include "RTClib.h"

// pins definitions for TM1637 and can be changed to other ports       
#define CLK 10
#define DIO 9

// TM1637 module
TM1637 tm1637(CLK,DIO);
// RTC1307 module
RTC_DS1307 RTC; 

// Holds current clock time
DateTime theTime;
// Digits displayed on the segment
int8_t TimeDisp[] = {0xff, 0xff, 0xff, 0xff};


void setup() { 
  Serial.begin(9600);
  Serial.println("------Group #4------");

  
  if (!RTC.begin()) {
    Serial.println("Couldn't find RTC");
    while(1);
  }
  
  if (!RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    RTC.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  
  tm1637.init();
  tm1637.set(2);         // TYPICAL = 2, DARKEST = 0, BRIGHTEST = 7;
}

int hour, minute, second;
unsigned char ClockPoint = 1;
 
void loop() {
  DateTime theTime = RTC.now();
  second = theTime.second();  // get seconds
  minute = theTime.minute();  // get minutes

  TimeDisp[0] = minute / 10;
  TimeDisp[1] = minute % 10;
  TimeDisp[2] = second / 10;
  TimeDisp[3] = second % 10;

  // Alpha C
  tm1637.display(0,12);
  //#4 group
  tm1637.display(1,4); 
  tm1637.display(2,TimeDisp[0]);
  tm1637.display(3,TimeDisp[1]);

  // print time
  Serial.print("Set to ");
  Serial.print(hour);
  Serial.print(":");
  Serial.print(minute);
  Serial.print(":");
  Serial.print(second);
  Serial.println();

  
  ClockPoint = (~ClockPoint) & 0x01;
  
  if(ClockPoint)
    tm1637.point(POINT_ON);
  else 
    tm1637.point(POINT_OFF);
    
  delay(1000);
}

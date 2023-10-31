#include <Grove_LED_Bar.h>

#include "Ultrasonic.h"


Ultrasonic myUltrasonicSensor(8);
LED_BLUE bar(2);


void setup()
{
 Serial.begin(9600);

 pinMode(myLed, OUTPUT);
 digitalWrite(myLed, 0);
}
void loop()
{
  long RangeInCentimeters;

  RangeInCentimeters = myUltrasonicSensor.MeasureInCentimeters(); // two measurements should keep an interval
  Serial.print(RangeInCentimeters);//0~400cm
  Serial.println(" cm");
  delay(250);
  bar.setLevel(2);
}

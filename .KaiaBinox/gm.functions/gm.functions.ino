#include <Grove_LED_Bar.h>

#include "Ultrasonic.h"


Ultrasonic myUSMIDDLE(8);
Ultrasonic myUSRIGHT(7);
Ultrasonic myUSLEFT(4);



void setup()
{
 Serial.begin(9600);


}
void loop()
{
  long MIDDLEUsRange;
  long RIGHTUsRange;
  long LEFTUsRange;

  MIDDLEUsRange = myUSMIDDLE.MeasureInCentimeters(); // two measurements should keep an interval
  Serial.print("MIDDLE:");
  Serial.print(MIDDLEUsRange);//0~400cm
  Serial.println(" cm");
  delay(250);

  RIGHTUsRange = myUSRIGHT.MeasureInCentimeters(); // two measurements should keep an interval
  Serial.print("RIGHT:");
  Serial.print(RIGHTUsRange);//0~400cm
  Serial.println(" cm");
  delay(250);

  LEFTUsRange = myUSLEFT.MeasureInCentimeters(); // two measurements should keep an interval
  Serial.print("LEFT:");
  Serial.print(LEFTUsRange);//0~400cm
  Serial.println(" cm");
  delay(250);

}

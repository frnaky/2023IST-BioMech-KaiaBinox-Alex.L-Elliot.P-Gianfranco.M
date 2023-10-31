#include <Grove_LED_Bar.h>
#include "Ultrasonic.h"

Ultrasonic myUltrasonicSensor(2);
Grove_LED_Bar myLEDBar(9, 8, 1);  // Assuming the LED Bar is connected to pin 9, 8, and using a 1-based index

void setup()
{
  Serial.begin(9600);
  myLEDBar.begin();  // Initialize the LED Bar
}

void loop()
{
  long RangeInCentimeters;

  RangeInCentimeters = myUltrasonicSensor.MeasureInCentimeters();
  Serial.print(RangeInCentimeters);
  Serial.println(" cm");

  // Check if the distance is within 0-50 cm
  if (RangeInCentimeters >= 0 && RangeInCentimeters <= 50) {
    // Set the LED Bar level to 9
    myLEDBar.setLevel(9);
  } else {
    // Map the range to LED levels (adjust these values based on your requirements)
    int ledLevel = map(RangeInCentimeters, 0, 400, 0, 10);

    // Constrain the LED level within the valid range
    ledLevel = constrain(ledLevel, 0, 10);

    // Set the LED Bar level
    myLEDBar.setLevel(ledLevel);
  }

  delay(250);
}

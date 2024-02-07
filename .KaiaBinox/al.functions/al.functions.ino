
#include <Wire.h>
#include "Grove_LED_Matrix_Driver_HT16K33.h"

#include "Ultrasonic.h"

Ultrasonic myUSMIDDLE(8); // US VARS
Ultrasonic myUSRIGHT(7);
Ultrasonic myUSLEFT(4);

// Create uint64_t type 8x8 matrix picture at
// https://xantorohara.github.io/led-matrix-editor/#
const uint64_t EXAMPLE[12] = { // idk why it has to be 12
    0xff07070707070707, // left       1
    0xffe0e0e0e0e0e0e0, // RIGHT BAR   2
    0x0707070707070707, // RIGHT BAR ( NOT DISPLAYING!!!) 3
    0x3f212d212d212121, // weird U thing displaying >???  4
    0xff99996624242418,   //dicl and bllas  5
    0xff99996624242418, //6
    0xff99996624242418,
    0xff99996624242418,
    0xff99996624242418,
    0xff99996624242418,
    0xff99996624242418,
    0xff99996624242418

};

Matrix_8x8 matrix;

void setup() {
    Wire.begin();
    matrix.init();
    matrix.setBrightness(0);
    matrix.setBlinkRate(BLINK_OFF);
    //dont touch^^

}

void loop() {
  long MIDDLEUsRange;
  long RIGHTUsRange;
  long LEFTUsRange;
  
  MIDDLEUsRange = myUSMIDDLE.MeasureInCentimeters(); // **DIRECTION**US RANGE is now US READINGS MEASURED IN CENTIMETERS
  RIGHTUsRange = myUSRIGHT.MeasureInCentimeters();
  LEFTUsRange = myUSRIGHT.MeasureInCentimeters();

Serial.print(MIDDLEUsRange);
  if (MIDDLEUsRange <=5000){
    Serial.print("poop");


  }

  matrix.writeOnePicture(EXAMPLE[5]);
  matrix.display();
/*
  MIDDLEUsRange = myUSMIDDLE.MeasureInCentimeters();
  Serial.print("MIDDLE:");
  Serial.print(MIDDLEUsRange);//0~400cm     // EXAMPLE CODE for US SENSOR middle lef and righr
  Serial.println(" cm");
  delay(250);
  */
  

    /*matrix.writeOnePicture(EXAMPLE[1]); // left
    matrix.display();
    delay(1000);                              // test code
    matrix.writeOnePicture(EXAMPLE[2]); // right
    matrix.display();
    delay(1000);
    */

}
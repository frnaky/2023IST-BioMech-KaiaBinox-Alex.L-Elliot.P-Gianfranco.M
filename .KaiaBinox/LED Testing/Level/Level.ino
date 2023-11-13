#include <Grove_LED_Matrix_Driver_HT16K33.h>
#include <I2Cdev.h>
#include <Seeed_Font.h>

#include <Wire.h>
#include <Grove_LED_Matrix_Driver_HT16K33.h>

// Define the number of displays
#define NUM_DISPLAYS 2

// Create an instance of the LED matrix driver
Grove_LED_Matrix_Driver_HT16K33 ledMatrix[NUM_DISPLAYS];

// Function to display a message on the LED matrix
void displayMessage(String message) {
  // Iterate through each display
  for (int i = 0; i < NUM_DISPLAYS; i++) {
    // Clear the display
    ledMatrix[i].clear();

    // Display the message on the current display
    ledMatrix[i].setText(message.substring(i * 4, (i + 1) * 4));

    // Update the display
    ledMatrix[i].update();
  }
}

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);

  // Initialize each LED matrix
  for (int i = 0; i < NUM_DISPLAYS; i++) {
    ledMatrix[i].begin();
    ledMatrix[i].setTextWrap(false);
    ledMatrix[i].setBrightness(15); // Adjust brightness (0 to 15)
  }
}

void loop() {
  // Your message to be displayed
  String message = "HELLO";

  // Display the message on the LED matrix
  displayMessage(message);

  // Optional: Delay between messages
  delay(2000);
}

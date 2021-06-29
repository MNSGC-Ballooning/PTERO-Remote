//function to operate and update the onboard Oled
#include <Wire.h>
#include <SPI.h>
#include <SFE_MicroOLED.h> // https://github.com/sparkfun/SparkFun_Micro_OLED_Arduino_Library
MicroOLED oled(PIN_RESET, DC_JUMPER);    // I2C declaration


void oledSetup(){
  Wire.begin();
  oled.begin();    // Initialize the OLED
  oled.clear(ALL); // Clear the display's internal memory
  oled.display();  // Display what's in the buffer (splashscreen)
  oled.clear(PAGE); // Clear the buffer.

  randomSeed(analogRead(A0) + analogRead(A1));

  updateOled("Initializing...");
  delay(500);
}

// take in string to display on the MicroOLED
void updateOled(String disp){
  oled.clear(PAGE);
  oled.setFontType(0);
  oled.setCursor(0, 0);
  oled.println(disp);
  oled.display();
}

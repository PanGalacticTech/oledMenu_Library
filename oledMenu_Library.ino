



//--------------------------------------------------### OLED Variables & Settings ###--------------------------
#include "globals.h

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <autoDelay.h>
#include <ledObject.h>
#include <rotaryEncoder.h>


#include <Fonts/FreeMonoBold12pt7b.h >
#include <Fonts/FreeSansBold12pt7b.h >
#include <Fonts/FreeSansBold9pt7b.h >

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)


#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Oled Pins

// SDA = A4;
// SLC = A5;


autoDelay testDelay;

autoDelay printDelay;

int printDelayTime = 100;    // seconds

ledObject led;



//----------------------------------------------
// ~~ ENCODER INPUT ~~


#define ENCODER_PIN_A 2
#define ENCODER_PIN_B 3

// Hardware Interrupts
// on Arduino UNO & NANo:
// = Pins 2 & 3
// 
// Only 1 interupt required for each encoder 
// So max TWO Encoder inputs.


#define ENCODER_BUTTON_PIN 4

// Set up instance of rotaryEncoder. Requires button pin, button active state, and 2 encoder pins.

rotaryEncoder encoderOne(ENCODER_BUTTON_PIN, BUTTON_PULL_HIGH, ENCODER_PIN_A, ENCODER_PIN_B);    





void setup() {

  Serial.begin(115200);

  oledSetup();

  led.begin(13 , 1);

  encoderOne.begin();    // encoder Begin function also calls the buttonObject begin function


//-- This is a fudge, as isr methods cannot be inside our rotaryEncoder library
// This is a workaround - Each instance of rotaryEncoder will require this line attaching 
// hardware interrupt to one of the encoders pins.

 attachInterrupt (digitalPinToInterrupt (ENCODER_PIN_A), isr , CHANGE);   // interrupt 0 is pin 2


}







bool printSerial = true;   // if true test serial output is printed.


void loop() {



  encoderOne.buttonLoop(750);   // long int passed controls the time required for a long press. (defaults to 1 second)

  encoderOne.encodeDirection();


  ledButtonFunctions();   // Test function to tie LED outputs to button inputs

  serialPrintout();

}




//-- This is a fudge, as isr methods cannot be inside our rotaryEncoder library
// This is a workaround

void isr (){

encoderOne.isr();

  
}

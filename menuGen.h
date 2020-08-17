/* --- Menu Generator Library -- menuGen.h ------
 *  
 *  This library is designed to be used with 
 * #include <Adafruit_GFX.h>
   #include <Adafruit_SSD1306.h>
 * 
 * Libraries.
 * 
 * It Creates a dervied object menuGen in order to allow
 * an easily navigated UI for use with OLED screens
 * 
 * 
 * 
 */


 // I Dont know if GFX will be required so it is excluded for now.




#include <Adafruit_SSD1306.h>

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


// Derived Class ------------// Base Class
class menuGen: public Adafruit_SSD1306.h {

  public:




    // Constructor
    menuGem(int buttonPin, int buttonActiveState, int encoder_pin_a, int encoder_pin_b):   // Note syntax and structure here: Important for implementing Derived Classes
      buttonObject (buttonPin, buttonActiveState),                                                  // BASE class is called without naming an instance, but passing any required values as arguments.

      encoderPinA(encoder_pin_a),                                                                     // Note commas and unsuaul punctuation.
      encoderPinB(encoder_pin_b)
    {
    }

  

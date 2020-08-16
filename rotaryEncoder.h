

#ifndef rotaryEncoder_h
#define rotaryEncoder_h

#if (ARDUINO >= 100)
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <buttonObject.h>




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Rotary Encoder Object ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Ran into a small problem in implementing this library.
// you cannot call an ISR routine from inside a class
//ISR routine needs to be external to library, but can pass known variables to the library.
// - Workaround - ISR function external to library simply calls the ISR routine from inside the library.




/*
    buttonObject is the BASE class

    rotaryEncoder is the DERIVED class

    https://stackoverflow.com/questions/120876/what-are-the-rules-for-calling-the-superclass-constructor
    THIS PAGE HELPS!

    //https://paulmurraycbr.github.io/ArduinoTheOOWay.html  << This page was very confusing

*/

// Derived Class
class rotaryEncoder: public buttonObject {

  public:


    int encoderPinA;
    int encoderPinB;

    // Constructor
    rotaryEncoder(int buttonPin, int buttonActiveState, int encoder_pin_a, int encoder_pin_b): 
    buttonObject (buttonPin, buttonActiveState),

      encoderPinA(encoder_pin_a),
      encoderPinB(encoder_pin_b)
    {
    }







    // Methods
    void begin();



    void encodeDirection();

    void  resetEncoder();

    void isr();

    // Variables



    bool rotaryUp;       // returns as true if encoder is turned up

    bool rotaryDown;     // returns as true if encoder is turned down.

    byte rotaryCount = 0;
    byte prevCount = 1;


  private:


    volatile bool fired;
    volatile bool up;


};




#endif

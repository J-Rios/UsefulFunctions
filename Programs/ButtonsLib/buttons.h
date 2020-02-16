/**************************************************************************************************/
// File: buttons.h
// Description: HAL library to ease Buttons control.
// Created on: 16 feb. 2020
// Last modified date: 16 feb. 2020
// Version: 1.0.0
/**************************************************************************************************/

/* Include Guard */

#ifndef BUTTONS_H_
#define BUTTONS_H_

/**************************************************************************************************/

/* Defines & Macros */

// Time between button reads (Software Debounce - non blocking)
#define TIME_TO_READ_MS 20

/**************************************************************************************************/

/* Libraries */

// Standard libraries
#include <stdint.h>

/**************************************************************************************************/

/* Library Data Types */


/**************************************************************************************************/

class Buttons
{
    public:

        // Buttons constructor
        Buttons(void);

        // Initialize Button GPIO as normal/pulldown/pullup input
        void setup(const uint8_t pin, const uint8_t pull_up);

        // Read the button digital logic level
        uint8_t read(void);

        // Check if button is currently pressed
        uint8_t is_pressed(void);

        // Check if button is currently released
        uint8_t is_released(void);

        // Check if button has been pressed
        // On button press, it return 1, but then it returns 0 until we release and press the 
        // button again
        uint8_t pressed(void);

        // Check if button has been pressed
        // On button release, it return 1, but then it returns 0 until we press and release the 
        // button again
        uint8_t released(void);


    private:
        // Private attributes
        uint8_t _pin, _was_pressed, _pull_up;
        uint32_t _t0;

        // Check if debounce time is completed
        // Used to know if we are able to read again from the GPIO pin
        uint8_t is_time_to_read(void);

};

/**************************************************************************************************/

#endif

/**************************************************************************************************/
// File: buttons.h
// Description: HAL library to ease Buttons control.
// Created on: 16 feb. 2020
// Last modified date: 16 feb. 2020
// Version: 1.0.0
/**************************************************************************************************/

/* Libraries */

#include "buttons.h"

/**************************************************************************************************/

/* Library Hardware Abstraction Functions */

// Hardware specific libraries
#if defined(ARDUINO)
    #include <Arduino.h>
#elif defined(ESP_IDF)
    #include <driver/gpio.h>
    #include <esp_timer.h>
#endif

// Functions
#if defined(ARDUINO)
    #define _pinMode(x, y) pinMode(x, y)
    #define _digitalRead(x) digitalRead(x)
    #define _millis() millis()
#elif defined(ESP_IDF)
    #define _pinMode(x, y) gpio_as_digital_input(x, y)
    #define _digitalRead(x) gpio_digital_read(x)
    #define _millis() (unsigned long)(esp_timer_get_time()/1000ULL)
#else
    #define _pinMode(x, y)
    #define _digitalRead(x)
    #define _millis()
#endif

/**************************************************************************************************/

/* Constructor */

// Buttons constructor
Buttons::Buttons(void)
{
    // Set default attributes values
    // If library user doesn't call setup() method to configure it
    _pin = 2;
    _was_pressed = 0;
    _pull_up = 1;
}

/**************************************************************************************************/

/* Public Methods */

// Initialize Button GPIO as normal/pulldown/pullup input
void Buttons::setup(const uint8_t pin, const uint8_t pull_up)
{
    _pin = pin;
    _pinMode(_pin, pull_up);
    _was_pressed = _digitalRead(_pin);

    if(pull_up)
        _pull_up = 1;
    else
        _pull_up = 0;

    _t0 = _millis();
}

// Read the button digital logic level
uint8_t Buttons::read(void)
{
    return _digitalRead(_pin);
}

// Check if button is currently pressed
uint8_t Buttons::is_pressed(void)
{
    return (read() == !_pull_up);
}

// Check if button is currently released
uint8_t Buttons::is_released(void)
{
    return (read() == _pull_up);
}

// Check if button has been pressed
// On button press, it return 1, but then it returns 0 until we release and press the button again
uint8_t Buttons::pressed(void)
{
    // Ignore if button is already pressed or it is still in debounce time
    if(_was_pressed)
        return 0;
    if(!is_time_to_read())
        return 0;

    if(is_pressed())
    {
        _was_pressed = 1;
        return 1;
    }

    return 0;
}

// Check if button has been pressed
// On button release, it return 1, but then it returns 0 until we release and press the button again
uint8_t Buttons::released(void)
{
    // Ignore if button is already released or it is still in debounce time
    if(!_was_pressed)
        return 0;
    if(!is_time_to_read())
        return 0;

    if(is_released())
    {
        _was_pressed = 0;
        return 1;
    }

    return 0;
}

/**************************************************************************************************/

/* Private Methods (Specific device HAL functions) */

// Check if debounce time is completed
// Used to know if we are able to read again from the GPIO pin
uint8_t Buttons::is_time_to_read(void)
{
    // Check if debounce time has been reach
    if(_millis() - _t0 >= TIME_TO_READ_MS)
    {
        _t0 = _millis();
        return 1;
    }

    return 0;
}

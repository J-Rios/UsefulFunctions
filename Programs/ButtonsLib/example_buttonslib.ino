
#include <Arduino.h>
#include "buttons.h"

/**************************************************************************************************/

#define GPIO_BUTTON 2

/**************************************************************************************************/

Buttons Button;

/**************************************************************************************************/

void setup()
{
    Serial.begin(115200);
    Button.setup(GPIO_BUTTON, INPUT_PULLUP);
}

void loop()
{
    if(Button.pressed())
        Serial.println("Button pressed");
    else if(Button.released())
        Serial.println("Button released");
}

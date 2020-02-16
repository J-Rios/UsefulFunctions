
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
    Button.setup(GPIO_BUTTON, INPUT, HIGH);
}

void loop()
{
    if(Button.pressed())
        Serial.println("Button pressed");
}

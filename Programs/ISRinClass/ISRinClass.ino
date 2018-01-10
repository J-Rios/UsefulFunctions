#include "class.h"

const byte interruptPin = 2;

uint8_t state;

ISRClass C(interruptPin);

void setup()
{
    Serial.begin(9600);
    state = C.stat();
    Serial.print("Initial state value: ");
    Serial.println(state);
}

void loop()
{
    if(C.stat() != state)
    {
        state = C.stat();
        Serial.print("State changed: ");
        Serial.println(state);
        delay(30);
    }
}


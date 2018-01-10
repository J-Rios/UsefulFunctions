#include "class.h"

/********************************************************************************/

ISRClass* isr_class_ptr;

void isr()
{
    isr_class_ptr->state = !isr_class_ptr->state;
}

/********************************************************************************/

ISRClass::ISRClass(const uint8_t pin)
{
    extern ISRClass* isr_class_ptr;
    isr_class_ptr = this;
    state = HIGH;

    pinMode(pin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(pin), isr, CHANGE);
}

uint8_t ISRClass::stat()
{
    return state;
}


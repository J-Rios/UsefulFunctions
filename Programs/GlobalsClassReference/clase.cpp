#include "clase.h"

Clase::Clase()
{
    _Global = NULL;
}

void Clase::init(Globals* Global)
{
    _Global = Global;
}

void Clase::set(int value)
{
    _Global->var = value;
}


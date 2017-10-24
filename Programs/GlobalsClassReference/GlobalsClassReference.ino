#include "globals.h"
#include "clase.h"

Globals Global;
Clase unaClase;

void setup()
{
    Serial.begin(9600);
    unaClase.init(&Global);

    Serial.println(Global.var); // 0
    unaClase.set(5);            // Global.var = 5
    Serial.println(Global.var); // 5
}

void loop()
{}


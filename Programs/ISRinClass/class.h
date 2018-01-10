#ifndef ISRCLASS_H
    #define ISRCLASS_H

    #include "Arduino.h"
    
    class ISRClass
    {
        public:
            volatile uint8_t state;
            
            ISRClass(const uint8_t pin);
            uint8_t stat(void);
    };

#endif

#ifndef CLASE_H
    #define CLASE_H

    #include <stddef.h> // NULL
    #include "globals.h"
    
    class Clase
    {
        public:
            Clase();
            void init(Globals* Global);
            void set(int value);
  
        private:
            Globals* _Global;
    };

#endif


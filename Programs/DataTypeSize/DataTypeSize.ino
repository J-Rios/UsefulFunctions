// DataTypeSize - Display information about data types used in a system

void setup()
{    
    Serial.begin(9600); 
}

void loop()
{
    Serial.println("");
    Serial.println("/************************************************************************/");
    Serial.println("/* DataTypeSize - Display information about data types used in a system */");
    Serial.println("/************************************************************************/");
    Serial.println("");
    
    Serial.print("boolean = ");
    Serial.print(sizeof(boolean));
    Serial.print(" bytes = ");
    Serial.print((sizeof(boolean))*8);
    Serial.println(" bits");
    
    Serial.print("char = ");
    Serial.print(sizeof(char));
    Serial.print(" bytes = ");
    Serial.print((sizeof(char))*8);
    Serial.println(" bits");
    
    Serial.print("int = ");
    Serial.print(sizeof(int));
    Serial.print(" bytes = ");
    Serial.print((sizeof(int))*8);
    Serial.println(" bits");

    Serial.print("long = ");
    Serial.print(sizeof(long));
    Serial.print(" bytes = ");
    Serial.print((sizeof(long))*8);
    Serial.println(" bits");

    Serial.print("float = ");
    Serial.print(sizeof(float));
    Serial.print(" bytes = ");
    Serial.print((sizeof(float))*8);
    Serial.println(" bits");

    Serial.print("double = ");
    Serial.print(sizeof(double));
    Serial.print(" bytes = ");
    Serial.print((sizeof(double))*8);
    Serial.println(" bits");

    Serial.print("byte = ");
    Serial.print(sizeof(byte));
    Serial.print(" bytes = ");
    Serial.print((sizeof(byte))*8);
    Serial.println(" bits");
    
    Serial.print("word = ");
    Serial.print(sizeof(word));
    Serial.print(" bytes = ");
    Serial.print((sizeof(word))*8);
    Serial.println(" bits");

    Serial.println("");
    
    Serial.print("unsigned char = ");
    Serial.print(sizeof(unsigned char));
    Serial.print(" bytes = ");
    Serial.print((sizeof(unsigned char))*8);
    Serial.println(" bits");

    Serial.print("unsigned int = ");
    Serial.print(sizeof(unsigned int));
    Serial.print(" bytes = ");
    Serial.print((sizeof(unsigned int))*8);
    Serial.println(" bits");

    Serial.print("unsigned long = ");
    Serial.print(sizeof(unsigned long));
    Serial.print(" bytes = ");
    Serial.print((sizeof(unsigned long))*8);
    Serial.println(" bits");

    Serial.println("");

    Serial.print("uint8_t = ");
    Serial.print(sizeof(uint8_t));
    Serial.print(" bytes = ");
    Serial.print((sizeof(uint8_t))*8);
    Serial.println(" bits");

    Serial.print("uint16_t = ");
    Serial.print(sizeof(uint16_t));
    Serial.print(" bytes = ");
    Serial.print((sizeof(uint16_t))*8);
    Serial.println(" bits");

    Serial.print("uint32_t = ");
    Serial.print(sizeof(uint32_t));
    Serial.print(" bytes = ");
    Serial.print((sizeof(uint32_t))*8);
    Serial.println(" bits");

    Serial.print("uint64_t = ");
    Serial.print(sizeof(uint64_t));
    Serial.print(" bytes = ");
    Serial.print((sizeof(uint64_t))*8);
    Serial.println(" bits");

    Serial.println("");
    
    delay(10000);
}

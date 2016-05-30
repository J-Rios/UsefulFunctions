
uint8_t lowNibble(uint8_t in) // Extract the Low Nibble from a Byte
{
    return (uint8_t)(in & 0x0F); // in data = asdfghjk; AND operation -> asdfghjk AND 00001111 = 0000ghjk
}

uint8_t highNibble(uint8_t in) // Extract the High Nibble from a Byte
{
    return (uint8_t)((in & 0xF0) >> 4); // in data = asdfghjk; AND operation -> asdfghjk AND 11110000 = asdf0000; Righ-Shift 4 times -> asdf0000 >> 4 = 0000asdf
}

uint8_t createByte(uint8_t lowNibble, uint8_t highNibble) // Create a Byte from Low and High Nibbles
{
    return (uint8_t)((highNibble << 4) | lowNibble); // Left-Shift 4 times the high Nibble -> 0000ghjk << 4 = asdf0000; OR operation -> asdf0000 OR 0000ghjk = asdfghjk
}

uint8_t getBit(uint8_t in, uint8_t num) // Get a bit value from a Byte
{
    return (uint8_t)((in & (1<<num)) >> num);
}

uint8_t setBit(uint8_t in, uint8_t num) // Set a bit value to a Byte
{
    return (uint8_t)(in | (1<<num));
}

uint8_t SRByte(uint8_t in, uint8_t steps) // Shift-Right Byte a number of steps
{
    return (uint8_t)(in >> steps);
}

uint8_t SLByte(uint8_t in, uint8_t steps) // Shift-Left Byte a number of steps
{
    return (uint8_t)(in << steps);
}

uint8_t NOT(uint8_t in)
{
    return (uint8_t)(~in);
}

uint8_t AND(uint8_t A, uint8_t B)
{
    return (uint8_t)(A & B);
}

uint8_t OR(uint8_t A, uint8_t B)
{
    return (uint8_t)(A | B);
}

uint8_t XOR(uint8_t A, uint8_t B)
{
    return (uint8_t)(A ^ B);
}

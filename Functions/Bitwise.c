
byte lowNibble(byte in) // Extract the Low Nibble from a Byte
{
    return (byte)(in & 0x0F); // in data = asdfghjk; AND operation -> asdfghjk AND 00001111 = 0000ghjk
}

byte highNibble(byte in) // Extract the High Nibble from a Byte
{
    return (byte)((in & 0xF0) >> 4); // in data = asdfghjk; AND operation -> asdfghjk AND 11110000 = asdf0000; Righ-Shift 4 times -> asdf0000 >> 4 = 0000asdf
}

byte createByte(byte lowNibble, byte highNibble) // Create a Byte from Low and High Nibbles
{
    return (byte)((highNibble << 4) | lowNibble); // Left-Shift 4 times the high Nibble -> 0000ghjk << 4 = asdf0000; OR operation -> asdf0000 OR 0000ghjk = asdfghjk
}

byte getBit(byte in, byte num) // Get a bit value from a Byte
{
    return (byte)((in & (1<<num)) >> num);
}

byte setBit(byte in, byte num) // Set a bit value to a Byte
{
    return (byte)(in | (1<<num));
}

byte SRByte(byte in, byte steps) // Shift-Right Byte a number of steps
{
    return (byte)(in >> steps);
}

byte SLByte(byte in, byte steps) // Shift-Left Byte a number of steps
{
    return (byte)(in << steps);
}

byte NOT(byte in)
{
    return (byte)(~in);
}

byte AND(byte A, byte B)
{
    return (byte)(A & B);
}

byte OR(byte A, byte B)
{
    return (byte)(A | B);
}

byte XOR(byte A, byte B)
{
    return (byte)(A ^ B);
}

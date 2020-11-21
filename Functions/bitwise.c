
/**
  * @brief  Return Bit value from given byte.
  * i.e.
  *   BIT_GET(0bABCDEFGH, 0): 0b0000000H
  *   BIT_GET(0bABCDEFGH, 3): 0b0000000E
  *   BIT_GET(0bABCDEFGH, 7): 0b0000000A
  * @param  data Data byte to get the bit value.
  * @param  bit_n Bit number (from LSB to MSB) of data byte to get the value.
  * @return Byte data bit value.
  */
static inline uint8_t BIT_GET(const uint8_t data, const uint8_t bit_n)
{   return ((data >> bit_n) & 0x01);   }
static inline uint8_t BIT_GET(const uint16_t data, const uint8_t bit_n)
{   return ((data >> bit_n) & 0x01);   }
static inline uint8_t BIT_GET(const uint32_t data, const uint8_t bit_n)
{   return ((data >> bit_n) & 0x01);   }


/**
  * @brief  Set a bit value of a Byte.
  * i.e.
  *   BIT_SET(0bABCDEFGH, 0): 0bABCDEFG1
  *   BIT_SET(0bABCDEFGH, 3): 0bABCD1FGH
  *   BIT_SET(0bABCDEFGH, 7): 0b1BCDEFGH
  * @param  data Data byte to set the bit value.
  * @param  bit_n Bit number (from LSB to MSB) of data byte to set.
  * @return provided byte with the bit set.
  */
static inline uint8_t BIT_SET(uint8_t data, uint8_t bit_n)
{   return (uint8_t)(data | (1<<bit_n));   }


/**
  * @brief  Clear a bit value of a Byte.
  * i.e.
  *   BIT_CLEAR(0bABCDEFGH, 0): 0bABCDEFG0
  *   BIT_CLEAR(0bABCDEFGH, 3): 0bABCD0FGH
  *   BIT_CLEAR(0bABCDEFGH, 7): 0b0BCDEFGH
  * @param  data Data byte to clear the bit value.
  * @param  bit_n Bit number (from LSB to MSB) of data byte to clear.
  * @return provided byte with the bit clear.
  */
static inline uint8_t BIT_CLEAR(uint8_t data, uint8_t bit_n)
{   return (uint8_t)(data & ~(1<<bit_n));   }


/**
  * @brief  Toggle a bit value of a Byte.
  * i.e.
  *   BIT_TOGGLE(0bABCDEF0H, 1): 0bABCDEF1H
  *   BIT_TOGGLE(0bABCDEF1H, 1): 0bABCDEF0H
  *   BIT_TOGGLE(0b0BCDEFGH, 7): 0b1BCDEFGH
  *   BIT_TOGGLE(0b1BCDEFGH, 7): 0b0BCDEFGH
  * @param  data Data byte to toggle the bit value.
  * @param  bit_n Bit number (from LSB to MSB) of data byte to toggle.
  * @return provided byte with the bit toggled.
  */
static inline uint8_t BIT_TOGGLE(uint8_t data, uint8_t bit_n)
{   return (uint8_t)(data ^ (1<<bit_n));   }


/**
  * @brief  Shift-Right Byte a number of steps.
  * i.e.
  *   SHIFT_RIGHT(0bABCDEFGH, 3): 0b000ABCDE
  *   SHIFT_RIGHT(0bABCDEFGH, 5): 0b00000ABC
  * @param  data Data byte value to shift.
  * @param  shift_steps Number of bit shifts to do.
  * @return Shifted byte.
  */
static inline uint8_t SHIFT_RIGHT(uint8_t data, uint8_t shift_steps)
{   return (uint8_t)(data >> shift_steps);   }


/**
  * @brief  Shift-Left Byte a number of steps.
  * i.e.
  *   SHIFT_LEFT(0bABCDEFGH, 3): 0bABCDH000
  *   SHIFT_LEFT(0bABCDEFGH, 5): 0bABH00000
  * @param  data Data byte value to shift.
  * @param  shift_steps Number of bit shifts to do.
  * @return Shifted byte.
  */
static inline uint8_t SHIFT_LEFT(uint8_t data, uint8_t shift_steps)
{   return (uint8_t)(data << shift_steps);   }


/**
  * @brief  Binary NOT operation.
  * i.e.
  *   NOT(0b11000111): 0b00111000
  * @param  data Data byte value to NOT.
  * @return NOT operation result.
  */
static inline uint8_t NOT(uint8_t in)
{   return (uint8_t)(~in);   }


/**
  * @brief  Binary AND operation.
  * i.e.
  *   AND(0b11000111, 0b01000110): 0b01000110
  * @param  data Data byte value to AND.
  * @return AND operation result.
  */
static inline uint8_t AND(uint8_t A, uint8_t B)
{   return (uint8_t)(A & B);   }


/**
  * @brief  Binary OR operation.
  * i.e.
  *   OR(0b11000111, 0b01010110): 0b11010111
  * @param  data Data byte value to OR.
  * @return OR operation result.
  */
static inline uint8_t OR(uint8_t A, uint8_t B)
{   return (uint8_t)(A | B);   }


/**
  * @brief  Binary XOR operation.
  * i.e.
  *   XOR(0b11000111, 0b01010110): 0b10010001
  * @param  data Data byte value to XOR.
  * @return XOR operation result.
  */
static inline uint8_t XOR(uint8_t A, uint8_t B)
{   return (uint8_t)(A ^ B);   }


/**
  * @brief  Get the Low Nibble from a Byte.
  * i.e.
  *   GET_LOW_NIBBLE(0bABCDEFGH): 0b0000EFGH
  *     0bABCDEFGH AND 0b00001111 = 0b0000EFGH
  * @param  data Data byte value to get low nibble from.
  * @return Low nibble of provided byte.
  */
static inline uint8_t GET_LOW_NIBBLE(uint8_t data)
{   return (uint8_t)(data & 0x0F);   }


/**
  * @brief  Get the High Nibble from a Byte.
  * i.e.
  *   GET_HIGH_NIBBLE(0bABCDEFGH): 0bABCD0000
  *     0bABCDEFGH AND 0b11110000 = 0bABCD0000
  * @param  data Data byte value to get high nibble from.
  * @return High nibble of provided byte.
  */
static inline uint8_t GET_HIGH_NIBBLE(uint8_t data)
{   return (uint8_t)((data & 0xF0) >> 4);   }


/**
  * @brief  Create a Byte from Low and High Nibbles.
  * i.e.
  *   BYTE_FROM_NIBBLES(0b0000EFGH, 0b0000ABCD): 0bABCDEFGH
  *     0b0000ABCD << 4 = 0bABCD0000; 0bABCD0000 OR 0b0000EFGH = 0bABCDEFGH
  * @param  low_nibble Low nibble to create the byte.
  * @param  high_nibble High nibble to create the byte.
  * @return Created byte from provided nibbles.
  */
static inline uint8_t BYTE_FROM_NIBBLES(uint8_t low_nibble, uint8_t high_nibble)
{   return (uint8_t)((high_nibble << 4) | low_nibble);   }


/**
  * @brief  Reverse bits of a given byte.
  * i.e.
  *   REVERSE_BITS(0bABCDEFGH): 0bHGFEDCBA
  * @param  data Data byte value to reverse bits.
  * @return Reversed byte bits data.
  */
static inline uint8_t REVERSE_BITS(const uint8_t data)
{
    return (((data & 0x80) >> 7) | ((data & 0x40) >> 5) |
            ((data & 0x20) >> 3) | ((data & 0x10) >> 1) |
            ((data & 0x01) << 7) | ((data & 0x02) << 5) |
            ((data & 0x04) << 3) | ((data & 0x08) >> 1));
}

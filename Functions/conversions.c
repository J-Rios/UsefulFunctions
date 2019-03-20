#include <stdint.h>

int32_t abs(int32_t x)
{
	if (x>=0)
		return x;
	else
		return (-x);
}

// Safe conversion a string number into uint8_t element
// in_str_len - number of bytes of in_str[] without null terminated byte
uint8_t safe_atoi_u8(const char* in_str, const uint8_t in_str_len, uint8_t* out_int)
{
	size_t converted_num;
	size_t multiplicator;

	// Check if input str has less or more chars than expected int32_t range (1 to 3 chars)
	if((in_str_len < 1) || (in_str_len > 3))
		return 0;

	// Check if input str is not terminated
	if(in_str[in_str_len] != '\0')
		return 0;

	// Check if any of the character of the str is not a number
	for(uint8_t i = 0; i < in_str_len; i++)
	{
		if(in_str[i] < '0' || in_str[i] > '9')
			return 0;
	}

	// Create the int
	converted_num = 0;
	for(uint8_t i = 0; i < in_str_len; i++)
	{
		multiplicator = 1;
		for(uint8_t ii = in_str_len-1-i; ii > 0; ii--)
			multiplicator = multiplicator * 10;

		converted_num = converted_num + (multiplicator * (in_str[i] - '0'));
	}

	// Check if number is higher than max uint8_t val
	if(converted_num > 255)
		return 0;

	// Get the converted number and return operation success
	*out_int = (uint8_t)converted_num;
	return 1;
}

// Safe conversion a string number into uint16_t element
// in_str_len - number of bytes of in_str[] without null terminated byte
uint8_t safe_atoi_u16(const char* in_str, const uint8_t in_str_len, uint16_t* out_int)
{
	size_t converted_num;
	size_t multiplicator;

	// Check if input str has less or more chars than expected int32_t range (1 to 3 chars)
	if((in_str_len < 1) || (in_str_len > 6))
		return 0;

	// Check if input str is not terminated
	if(in_str[in_str_len] != '\0')
		return 0;

	// Check if any of the character of the str is not a number
	for(uint8_t i = 0; i < in_str_len; i++)
	{
		if(in_str[i] < '0' || in_str[i] > '9')
			return 0;
	}

	// Create the int
	converted_num = 0;
	for(uint8_t i = 0; i < in_str_len; i++)
	{
		multiplicator = 1;
		for(uint8_t ii = in_str_len-1-i; ii > 0; ii--)
			multiplicator = multiplicator * 10;

		converted_num = converted_num + (multiplicator * (in_str[i] - '0'));
	}

	// Check if number is higher than max uint16_t val
	if(converted_num > 65535)
		return 0;

	// Get the converted number and return operation success
	*out_int = (uint16_t)converted_num;
	return 1;
}

// Safe conversion a string number into uint32_t element
// in_str_len - number of bytes of in_str[] without null terminated byte
uint8_t safe_atoi_u32(const char* in_str, const uint8_t in_str_len, uint32_t* out_int)
{
	size_t converted_num;
	size_t multiplicator;

	// Check if input str has less or more chars than expected int32_t range (1 to 3 chars)
	if((in_str_len < 1) || (in_str_len > 10))
		return 0;

	// Check if input str is not terminated
	if(in_str[in_str_len] != '\0')
		return 0;

	// Check if any of the character of the str is not a number
	for(uint8_t i = 0; i < in_str_len; i++)
	{
		if(in_str[i] < '0' || in_str[i] > '9')
			return 0;
	}

	// Create the int
	converted_num = 0;
	for(uint8_t i = 0; i < in_str_len; i++)
	{
		multiplicator = 1;
		for(uint8_t ii = in_str_len-1-i; ii > 0; ii--)
			multiplicator = multiplicator * 10;

		converted_num = converted_num + (multiplicator * (in_str[i] - '0'));
	}

	// Check if number is higher than max uint32_t val
	if(converted_num > 4294967295UL)
		return 0;

	// Get the converted number and return operation success
	*out_int = (uint32_t)converted_num;
	return 1;
}

// Safe conversion a string number into int8_t element
// in_str_len - number of bytes of in_str[] without null terminated byte
uint8_t safe_atoi_i8(const char* in_str, uint8_t in_str_len, int8_t* out_int)
{
	int64_t converted_num;
	size_t multiplicator;
	int8_t sign = 1;

	if(in_str[0] == '-')
	{
		sign = -1;
		in_str = in_str + 1;
		in_str_len = in_str_len - 1;
	}
	else if(in_str[0] == '+')
	{
		in_str = in_str + 1;
		in_str_len = in_str_len - 1;
	}
		
	// Check if input str has less or more chars than expected int32_t range (1 to 3 chars)
	if((in_str_len < 1) || (in_str_len > 3))
		return 0;

	// Check if input str is not terminated
	if(in_str[in_str_len] != '\0')
		return 0;

	// Check if any of the character of the str is not a number
	for(uint8_t i = 0; i < in_str_len; i++)
	{
		if(in_str[i] < '0' || in_str[i] > '9')
			return 0;
	}

	// Create the int
	converted_num = 0;
	for(uint8_t i = 0; i < in_str_len; i++)
	{
		multiplicator = 1;
		for(uint8_t ii = in_str_len-1-i; ii > 0; ii--)
			multiplicator = multiplicator * 10;

		converted_num = converted_num + (multiplicator * (in_str[i] - '0'));
	}
	converted_num = sign * converted_num;

	// Check if number is inside int8_t range (-128 to +127)
	if((converted_num < -128) || (converted_num > 127))
		return 0;

	// Get the converted number and return operation success
	*out_int = (int8_t)converted_num;
	return 1;
}

// Safe conversion a string number into int16_t element
// in_str_len - number of bytes of in_str[] without null terminated byte
uint8_t safe_atoi_i16(const char* in_str, uint8_t in_str_len, int16_t* out_int)
{
	int64_t converted_num;
	size_t multiplicator;
	int8_t sign = 1;

	if(in_str[0] == '-')
	{
		sign = -1;
		in_str = in_str + 1;
		in_str_len = in_str_len - 1;
	}
	else if(in_str[0] == '+')
	{
		in_str = in_str + 1;
		in_str_len = in_str_len - 1;
	}
	
	// Check if input str has less or more chars than expected int32_t range (1 to 5 chars)
	if((in_str_len < 1) || (in_str_len > 5))
		return 0;

	// Check if input str is not terminated
	if(in_str[in_str_len] != '\0')
		return 0;

	// Check if any of the character of the str is not a number
	for(uint8_t i = 0; i < in_str_len; i++)
	{
		if(in_str[i] < '0' || in_str[i] > '9')
			return 0;
	}

	// Create the int
	converted_num = 0;
	for(uint8_t i = 0; i < in_str_len; i++)
	{
		multiplicator = 1;
		for(uint8_t ii = in_str_len-1-i; ii > 0; ii--)
			multiplicator = multiplicator * 10;

		converted_num = converted_num + (multiplicator * (in_str[i] - '0'));
	}
	converted_num = sign * converted_num;

	// Check if number is inside int16_t range (-32768 to +32767)
	if((converted_num < -32768) || (converted_num > 32767))
		return 0;

	// Get the converted number and return operation success
	*out_int = (int16_t)converted_num;
	return 1;
}

// Safe conversion a string number into int32_t element
// in_str_len - number of bytes of in_str[] without null terminated byte
uint8_t safe_atoi_i32(const char* in_str, uint8_t in_str_len, int32_t* out_int)
{
	int64_t converted_num;
	size_t multiplicator;
	int8_t sign = 1;

	if(in_str[0] == '-')
	{
		sign = -1;
		in_str = in_str + 1;
		in_str_len = in_str_len - 1;
	}
	else if(in_str[0] == '+')
	{
		in_str = in_str + 1;
		in_str_len = in_str_len - 1;
	}
	
	// Check if input str has less or more chars than expected int32_t range (1 to 10 chars)
	if((in_str_len < 1) || (in_str_len > 10))
		return 0;

	// Check if input str is not terminated
	if(in_str[in_str_len] != '\0')
		return 0;

	// Check if any of the character of the str is not a number
	for(uint8_t i = 0; i < in_str_len; i++)
	{
		if(in_str[i] < '0' || in_str[i] > '9')
			return 0;
	}

	// Create the int
	converted_num = 0;
	for(uint8_t i = 0; i < in_str_len; i++)
	{
		multiplicator = 1;
		for(uint8_t ii = in_str_len-1-i; ii > 0; ii--)
			multiplicator = multiplicator * 10;

		converted_num = converted_num + (multiplicator * (in_str[i] - '0'));
	}
	converted_num = sign * converted_num;

	// Check if number is inside int32_t range (-2147483648 to +2147483647)
	if((converted_num < -2147483648LL) || (converted_num > 2147483647UL))
		return 0;

	// Get the converted number and return operation success
	*out_int = (int32_t)converted_num;
	return 1;
}


/*************************************************************************************************/

/*** Interface ***/

void str_rm_char(char* str, const char c_remove, char* readed=NULL);
bool str_contains(const char* s1, const char* s2);
bool str_read_until_char(char* str, const char c, char* readed=NULL, const bool preserve=false);
bool str_read_until_word(char* str, const char* word, char* readed=NULL, const bool preserve=false);
size_t str_read_between_chars(char* str, const char c, char* readed, const size_t readed_len, size_t start_at=0, const bool preserve=true);
bool str_read_line(char* str, char* readed=NULL, const bool preserve=false);
void str_rm_left_zeros(char* str, char* readed=NULL);
int str_to_int(const char* str_in);
bool str_is_number(const char* s);
char* int_to_str(int int_in);
bool str_is_number(const char* s);
bool str_is_IP(const char* str);

/*************************************************************************************************/

/*** Implementation ***/

// Remove all specific char from a string (str: "1 2 3 4 5" -> remove ' ' -> str: "12345")
void str_rm_char(char* str, const char c_remove, char* readed)
{
	uint16_t a, b; // strlen(str) < 65536

	a = 0;
	if(readed == NULL)
	{
		for(b = 0; b <= strlen(str); b++)
		{
			if(str[b] != c_remove)
			{
				str[a] = str[b];
				a = a + 1;
			}
		}
		str[a] = '\0';
	}
	else
	{
		for(b = 0; b <= strlen(str); b++)
		{
			if(str[b] != c_remove)
			{
				readed[a] = str[b];
				a = a + 1;
			}
		}
		readed[a] = '\0';
	}
}

// Check if a string contains a subtring  (str: "asdf qwerty lkjh" -> remove " qwerty" -> str: "asdf lkjh")
bool str_contains(const char* s1, const char* s2)
{
	size_t length_s1 = strlen(s1);
	size_t length_s2 = strlen(s2);
	
	if((length_s1 == 0) || (length_s2 == 0))
		return false;
	if(length_s1 < length_s2)
		return false;
	
	char substr[length_s2+1];
	for (size_t i = 0; i < length_s1+1; i++)
	{
		if(i+length_s2 < length_s1+1)
		{
			memcpy(substr, &s1[i], length_s2);
			substr[length_s2] = '\0';
			if (strcmp(substr, s2) == 0)
				return true;
		}
		else
			break;
	}
	
	return false;
}

// Read a line of an array
bool str_read_line(char* str, char* readed, const bool preserve)
{
	uint16_t i;
	bool found = false;

	if(str_read_until_char(str, '\n', readed, preserve))
	{
		// Remove '\n' character in readed data
		readed[strlen(readed)-1] = '\0';
	}

	return found;
}

// Read array until a specific char. The input string (str) split his content into readed chars (readed) and keep not readed ones
bool str_read_until_char(char* str, const char c, char* readed, const bool preserve)
{
	const uint16_t readed_len = strlen(str);
	char char_read = '\0';
	uint16_t a, b, i;
	bool found = false;
	
	i = 0;
	while(i < strlen(str) + 1)
	{
		char_read = str[i];
		//printf("%c", char_read);

		if(i < readed_len)
		{
			if(readed != NULL)
				readed[i] = char_read;
		}

		i = i + 1;

		if(char_read == c)
		{
			if(readed != NULL)
				readed[i] = '\0';

			// Remove readed data from str
			if(!preserve)
			{
				a = 0; b = i;
				while(b < strlen(str))
				{
					str[a] = str[b];
					a = a + 1;
					b = b + 1;
				}
				str[a] = '\0';
			}

			found = true;
			break;
		}
	}

	if(readed != NULL)
		readed[readed_len] = '\0';

	return found;
}

// Read array until a specific word. The input string (str) split his content into readed chars (readed) and keep not readed ones
bool str_read_until_word(char* str, const char* word, char* readed, const bool preserve)
{
	const uint16_t readed_len = strlen(str);
	char* read_word = new char[strlen(word) + 1]();
	char char_read = '\0';
	uint16_t a, b, i;
	bool found = false;

	a = 0;	b = 0;	i = 0;
	memset(read_word, '\0', sizeof(strlen(word) + 1));
	while(i < strlen(str) + 1)
	{
		char_read = str[i];
		//printf("%c", char_read);

		if((readed_len > 0) && (a < readed_len - 1))
		{
			if(readed != NULL)
				readed[a] = char_read;
			a = a + 1;
		}

		if(char_read == word[b])
		{
			if(b < strlen(word))
			{
				read_word[b] = char_read;
				b = b + 1;
			}

			if(b == strlen(word))
			{
				read_word[b] = '\0';
				if(strcmp(read_word, word) == 0)
				{
					if(readed != NULL)
						readed[a] = '\0';

					// Remove readed data from str
					if(!preserve)
					{
						a = 0;
						i = i + 1;
						while(i < strlen(str))
						{
							str[a] = str[i];
							a = a + 1;
							i = i + 1;
						}
						str[a] = '\0';
					}

					found = true;
					break;
				}
			}
		}
		else
		{
			b = 0;
			memset(read_word, '\0', sizeof(strlen(word) + 1));
		}

		i = i + 1;
	}

	if(readed != NULL)
		readed[readed_len] = '\0';

	return found;
}

size_t str_read_between_chars(char* str, const char c, char* readed, const size_t readed_len, size_t start_at, const bool preserve)
{
	size_t str_len = strlen(str);
	size_t second_char_at = 0;
	bool first_char_reach = false;
	bool second_char_reach = false;
	size_t r = 0;
	char read_c;
	
	// If start position if out of string
	if(start_at >= str_len-1)
		return 0;
	
	// Go through the string and search for substring
	for(size_t i = start_at; i < str_len; i++)
	{
		read_c = str[i];
		if(read_c == c)
			first_char_reach = true;
		
		if(first_char_reach)
		{
			if(read_c == c)
			{
				second_char_reach = true;
				second_char_at = i + 1;
				break;
			}
			
			if(r < readed_len-1)
			{
				readed[r] = read_c;
				r = r + 1;
			}
		}
	}
	
	// Set end of string character in read
	readed[r] = '\0';
}

// Remove left '0's of a string (str: "000012gd00adw0" -> str: "12gd00adw0")
void str_rm_left_zeros(char* str, char* readed)
{
	uint16_t a, b; // strlen(str) < 65536
	bool zero_yet;

	if(str[0] == '0')
		zero_yet = true;
	else
		zero_yet = false;

	a = 0;
	if(readed == NULL)
	{
		for(b = 0; b < strlen(str); b++)
		{
			if(zero_yet)
			{
				if(str[b] != '0')
				{
					str[a] = str[b];
					a = a + 1;
					zero_yet = false;
				}
			}
			else
			{
				str[a] = str[b];
				a = a + 1;
			}
		}
		str[a] = '\0';
	}
	else
	{
		for(b = 0; b < strlen(str); b++)
		{
			if(zero_yet)
			{
				if(str[b] != '0')
				{
					readed[a] = str[b];
					a = a + 1;
					zero_yet = false;
				}
			}
			else
			{
				readed[a] = str[b];
				a = a + 1;
			}
		}
		readed[a] = '\0';
	}
}

// Convert int to string
char* int_to_str(int int_in)
{
	char* str_out = new char[sizeof(int)+1]();

	memset(str_out, '\0', sizeof(int)+1);
	sprintf(str_out, "%d", int_in);

	return str_out;
}

// Convert string to int
int str_to_int(const char* str_in)
{
	int int_out = 0;

	for(int i = 0; i < strlen(str_in); i++)
		int_out = int_out * 10 + (str_in[i] - '0');

	return int_out;
}

// Check if a string is a number
bool str_is_number(const char* s)
{
	bool is_number = true;

	while(*s)
	{
		if((*s < '0') || (*s > '9'))
		{
			is_number = false;
			break;
		}
		else
			s++;
	}

	return is_number;
}

// Check if a string has a valid IP format
bool str_is_IP(const char* str)
{
	bool is_ip = false;
	uint8_t i;
	uint8_t num_dots = 0;
	int8_t dots_places[3] = { -1, -1, -1 };

	// If str has a max lenght equal to max IP lenght or less
	if(strlen(str) <= 15)
	{
		// Check if the format of the string is corresponding to an IP adderss
		for(i = 0; i < strlen(str); i++)
		{
			// If there is a '.'
			if(str[i] == '.')
			{
				if(dots_places[0] == -1)
					dots_places[0] = i;
				else if(dots_places[1] == -1)
					dots_places[1] = i;
				else if(dots_places[2] == -1)
					dots_places[2] = i;

				num_dots++;
			}
			// If there is a null end of string character
			else if(str[i] == '\0')
				break;
			// If there is a character that is not a '.', '\0' or a number
			else if((str[i] < '0') || (str[i] > '9'))
			{
				num_dots = 0;
				break;
			}
		}

		// If there is 3 points in the string
		if(num_dots == 3)
		{
			// Check if points '.' are in correct places (min one number between points)
			if((dots_places[0] > 0) && (dots_places[0] <= 3))
			{
				if((dots_places[1] > dots_places[0] + 1) && (dots_places[1] <= 7))
				{
					if((dots_places[2] > dots_places[1] + 1) && (dots_places[1] <= 11))
						is_ip = true;
				}
			}
		}
	}

	return is_ip;
}

/*************************************************************************************************/

/*** Usage ***/

char str[256] = "000123-400\n0056-189-a11-qw0e-ty10";
char read[256] = "";

/*****************************************/

// Read Until Word
/*printf("Init:\n%s\n", str);
str_read_until_word(str, "-asd");
printf("\nRemain:\n%s\n", str);*/

/*printf("Init:\n%s\n", str);
str_read_until_word(str, "-asd", read);
printf("\nRead:\n%s\n", read);
printf("\nRemain:\n%s\n", str);*/

/*****************************************/

// Read Until Char
/*printf("Init:\n%s\n", str);
str_read_until_char(str, '9');
printf("\nRemain:\n%s\n", str);*/

/*printf("Init:\n%s\n", str);
str_read_until_char(str, '9', read);
printf("\nRead:\n%s\n", read);
printf("\nRemain:\n%s\n", str);*/

/*****************************************/

// Read Line
/*printf("Init:\n%s\n", str);
str_read_line(str, read, true);
printf("\nRead:\n%s\n", read);
printf("\nRemain:\n%s\n", str);*/

/*****************************************/

// String contains subtring
/*printf("Init:\n%s\n", str);
if(str_contains(str, "ale"))
	printf("\nContained\n");
else
	printf("\nNot contained\n");*/

/*****************************************/

// String Remove chars
/*printf("Init:\n%s\n", str);
str_rm_char(str, '1', read);
printf("\nRead:\n%s\n", read);
printf("\nRemain:\n%s\n", str);*/

/*****************************************/

// Remove left Zeros
/*printf("Init:\n%s\n", str);
str_rm_left_zeros(str);
printf("\nRead:\n%s\n", read);
printf("\nRemain:\n%s\n", str);*/

/*****************************************/

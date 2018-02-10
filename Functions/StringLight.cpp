
/*************************************************************************************************/

/*** Interface ***/

void str_rm_char(char* str, const char c_remove, char* readed=NULL);
bool str_contains(char* str, const char* word);
bool str_read_until_char(char* str, const char c, char* readed=NULL, const bool preserve=false);
bool str_read_until_word(char* str, const char* word, char* readed=NULL, const bool preserve=false);
bool str_read_line(char* str, char* readed=NULL, const bool preserve=false);
void str_rm_left_zeros(char* str, char* readed=NULL);

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
bool str_contains(char* str, const char* word)
{
	bool found = false;
	char* read_word = new char[strlen(word) + 1]();
	uint16_t a, b; // strlen(str) < 65536
	char char_read = '\0';

	a = 0;
	b = 0;
	memset(read_word, '\0', sizeof(strlen(word) + 1));
	while(a < strlen(str) + 1)
	{
		char_read = str[a];

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

		a = a + 1;
	}

	return found;
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

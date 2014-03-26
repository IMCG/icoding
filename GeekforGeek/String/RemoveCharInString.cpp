/*Given a string, eliminate all “b” and “ac” in the string, you have to replace 
them in-place, and you are only allowed to iterate over the string once. 
(Source Google Interview Question)

Examples:

acbac   ==>  ""
aaac    ==>  aa
ababac  ==>   aa
bbbbd   ==>   d

1. Filtering of all ‘b’ and ‘ac’ should be in single pass
2. No extra space allowed.
*/
//Have extra space .
string stringFilter(string&str)
{
	string result;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == 'b')
			continue;
		else if (str[i] == 'a')
		{
			result.push_back(str[i]);
			if (i + 1 < str.length() && str[i + 1] == 'c'){
				result.pop_back();
				i += 1;
			}
		}
		else
			result.push_back(str[i]);
	}
	return result;
}

//geeksforgeeks  No extra space
void stringFilter(char *str)
{
	int i = 0, j;
	for (j = 0; *(str + j); j++)
	{
		if (*(str + j) == 'b')
			continue;
		else if (*(str+j) == 'a'){
			if (*(str + j + 1) && *(str + j + 1) == 'c')
				j += 1;
			else
				str[i++] = *(str+j);
		}
		else
			str[i++] = *(str+j);
	}
	str[i] = '\0';
}
//geeksforgeeks  
//Using state machine  
#define ONE 1
#define TWO 2

// The main function that removes occurences of "a" and "bc" in input string
void stringFilter(char *str)
{
	// state is initially ONE (The previous character is not a)
	int state = ONE;

	// i and j are index variables, i is used to read next character of input
	// string, j is used for indexes of output string (modified input string)
	int j = 0;

	// Process all characters of input string one by one
	for (int i = 0; str[i] != '\0'; i++)
	{
		/* If state is ONE, then do NOT copy the current character to output if
		one of the following conditions is true
		...a) Current character is 'b' (We need to remove 'b')
		...b) Current character is 'a' (Next character may be 'c') */
		if (state == ONE && str[i] != 'a' && str[i] != 'b')
		{
			str[j] = str[i];
			j++;
		}

		// If state is TWO and current character is not 'c' (otherwise
		// we ignore both previous and current characters)
		if (state == TWO && str[i] != 'c')
		{
			// First copy the previous 'a'
			str[j] = 'a';
			j++;

			// Then copy the current character if it is not 'a' and 'b'
			if (str[i] != 'a' && str[i] != 'b')
			{
				str[j] = str[i];
				j++;
			}
		}

		// Change state according to current character
		state = (str[i] == 'a') ? TWO : ONE;
	}

	// If last character was 'a', copy it to output
	if (state == TWO)
	{
		str[j] = 'a';
		j++;
	}

	// Set the string terminator
	str[j] = '\0';
}
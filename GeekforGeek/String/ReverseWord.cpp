#include<stdio.h>

/* function prototype for utility function to
reverse a string from begin to end  */
void reverse(char *begin, char *end);

/*Function to reverse words*/
//没考虑  前面都是空格的情况
void reverseWords(char *s)
{
	char *word_begin = s;
	char *temp = s; /* temp is for word boundry */

	/*while (*temp == ' '){
		word_begin++;
		temp++;
	}
	*/
	/*STEP 1 of the above algorithm */
	while (*temp)
	{
		temp++;
		if (*temp == '\0')
		{
			reverse(word_begin, temp - 1);
		}
		else if (*temp == ' ')
		{
			reverse(word_begin, temp - 1);
			word_begin = temp + 1;
		}
	} /* End of while */

	/*STEP 2 of the above algorithm */
	reverse(s, temp - 1);
}

/* UTILITY FUNCTIONS */
/*Function to reverse any sequence starting with pointer
begin and ending with pointer end  */
void reverse(char *begin, char *end)
{
	char temp;
	while (begin < end)
	{
		temp = *begin;
		*begin++ = *end;
		*end-- = temp;
	}
}

/* Driver function to test above functions */
int main()
{
	char s[] = "i like this program very much";
	char *temp = s;
	reverseWords(s);
	printf("%s", s);
	getchar();
	return 0;
}
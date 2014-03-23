#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;
string RunLengthEncoding(string&str)
{
	const int m = str.length();
	string result;
	for (auto it = str.begin(); it != str.end();)
	{
		char add = *it;
		result += add;
		auto pos = find_if_not(it, str.end(),bind1st(equal_to<char>(),add));
		int dis = distance(it, pos);
		result += dis + '0';
		it = pos;
	}
	return result;
}
int main()
{
	string str = "wwwwaaadexxxxxx";
	string res = RunLengthEncoding(str);
	cout << res;
}

//
#define MAX_RLEN 50

/* Returns the Run Length Encoded string for the
source string src */
char *encode(char *src)
{
	int rLen;
	char count[MAX_RLEN];
	int len = strlen(src);

	/* If all characters in the source string are different,
	then size of destination string would be twice of input string.
	For example if the src is "abcd", then dest would be "a1b1c1d1"
	For other inputs, size would be less than twice.  */
	char *dest = (char *)malloc(sizeof(char)*(len * 2 + 1));

	int i, j = 0, k;

	/* traverse the input string one by one */
	for (i = 0; i < len; i++)
	{

		/* Copy the first occurrence of the new character */
		dest[j++] = src[i];

		/* Count the number of occurrences of the new character */
		rLen = 1;
		while (i + 1 < len && src[i] == src[i + 1])
		{
			rLen++;
			i++;
		}

		/* Store rLen in a character array count[] */
		sprintf(count, "%d", rLen);

		/* Copy the count[] to destination */
		// 考虑到个数大于10的时候
		for (k = 0; *(count + k); k++, j++)
		{
			dest[j] = count[k];
		}
	}

	/*terminate the destination string */
	dest[j] = '\0';
	return dest;
}


//Write formatted data to string
/* sprintf example */
////sprintf_s
#include <stdio.h>

int main ()
{
  char buffer [50];
  int n, a=5, b=3;
  n=sprintf (buffer, "%d plus %d is %d", a, b, a+b);
  printf ("[%s] is a string %d chars long\n",buffer,n);
  return 0;
}

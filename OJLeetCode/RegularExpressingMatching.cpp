//Regular Expressing Matching
#include<iostream>
#include<cassert>
using namespace std;
bool isMatch(const char*s, const char*p)
{
	assert(s&&p);
	if (*p == '\0')return *s == '\0';
	//next char is not'*':must match current char
	if (*(p + 1) != '*'){
		assert(*p != '*');
		return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s + 1, p + 1);
	}
	//nest char is'*'
	while ((*p == *s) || (*p == '.' && *s != '\0')){
		if (isMatch(s, p + 2))return true;
		s++;
	}
	return isMatch(s, p + 2);
}
bool isMatch1(const char*s, const char*p)
{
	if (*p == '\0')return *s == '\0';

	//next char is not '*' then match current char
	if (*(p + 1) != '*'){
		if (*p == *s || (*p == '.' && *s != '\0'))
			return isMatch1(s + 1, p + 1);
		else
			return false;
	}
	else
	{	//next char is '*'
		while (*p == *s || (*p == '.' && *s != '\0')){
			if (isMatch1(s, p + 2))
				return true;
			s++;
		}
		return isMatch1(s, p + 2);
	}
}
int main()
{
	char*str1 = "aab";
	char*str2 = "c*a*b";
	cout << boolalpha << isMatch1(str1, str2);
}
//Implement strStr()
#include <iostream>
#include <cstring>
using namespace std;
//暴力解决
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
       if (!*needle)return (char*)haystack;
	const char*p1;
	const char*p2;
	const char*p1_advance = haystack;
	for (p2 = &needle[1]; *p2; ++p2)
		p1_advance++;//advance p1_advance M-1 times
	for (p1 = haystack; *p1_advance; p1_advance++){
		char *p1_old = (char*)p1;
		p2 = needle;
		while (*p1 && *p2 && *p1 == *p2){
			p1++;
			p2++;
		}
		if (!*p2)return p1_old;
		p1 = p1_old + 1;
	}
	return nullptr;
    }
};
char*strStr(const char*src, const char*det)
{
	const char*p1 = src;
	const char*p2 = det;
	int len = strlen(p1);
	for (int i = 0; i < len; i++)
	{
		while (*(p1 + i) == *(p2))
		{
			p1++;
			p2++;
		}
		if (*(p2) == '\0')
			return (char*)(p1+i);
	}
	return nullptr;
}
char*my_strstr(const char*src, const char*det)
{
	int n;
	const char*s1 = src;
	const char*s2 = det;
	if (*s2 == '\0' || s2 == nullptr)
	{
		return  const_cast<char*>(s1);//类型转换
	}
	while (*src != '\0')
	{
		for (n = 0; *(s1 + n) == *(s2 + n); n++)
		{
			if (*(s2 + n + 1) == '\0')
				return const_cast<char*>(s1);
		}
		s1++;
	}
	return nullptr;
}
int main()
{
	const char*p1 = "mynameisbob";
	const char*p2 = "name";
	char* test = strStr(p1, p2);
	cout << p1<<"\n"<<test;
}
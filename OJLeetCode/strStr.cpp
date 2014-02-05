//Implement strStr()
#include<iostream>
#include<cstring>
using namespace std;
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
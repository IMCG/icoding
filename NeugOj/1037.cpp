//字符移动
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char c1 = 'C';
	char c2 = 'h';
	char c3 = 'i';
	char c4 = 'n';
	char c5 = 'a';
	c1 = (char)(c1 + 4);
	c2 = (char)(c2 + 4);
	c3 = (char)(c3 + 4);
	c4 = (char)(c4 + 4);
	c5 = (char)(c5 + 4);
	cout << c1 << c2 << c3 << c4 << c5;
}
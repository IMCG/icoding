//统计字符
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int a, b, c, d;
int main()
{
	string str;
	//使用getline而不是cin   cin会议空格为中断
	getline(cin, str);
	for (auto& ch : str){
		if (isalpha(ch))
			a++;
		else if (isspace(ch))
			b++;
		else if (isdigit(ch))
			c++;
		else
			d++;
	}
	cout << a << "\n" << b << "\n"
		<< c << "\n" << d << "\n";
	return 0;
}
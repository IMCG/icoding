#include <regex>
#include <iostream>
#include <string>
using namespace std;
/*\d 是匹配一个数字，{,}表示数字的个数。{1,3}匹配一个小于1000的数字。1-3位都符合要求
@ match_results类，用来保存每一个匹配的子序列。
*/
void show_ip_parts(const string&ip)
{
	const regex pattern("(\\d{1,3}):(\\d{1,3}):(\\d{1,3}):(\\d{1,3})");
	match_results<string::const_iterator>result;
	//match IP with the regular expression
	bool valid = regex_match(ip, result, pattern);
	cout << ip << "\t" << boolalpha << valid << endl;
	//if the Ip matched the regex, then print the parts
	if (valid)
	{
		cout << "b1:" << result[1] << endl;
		cout << "b2:" << result[2] << endl;
		cout << "b3:" << result[3] << endl;
		cout << "b4:" << result[4] << endl;
	}
}
int main()
{
	show_ip_parts("1:22:33:444");

	show_ip_parts("1:22:33:4444");

	show_ip_parts("100:200");
}
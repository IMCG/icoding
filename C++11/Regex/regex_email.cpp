//is_email_valid.C++11 regex
#include <regex>
#include <iostream>
#include <string>
using namespace std;
/* 首先注意‘()’表示将正则表达式分成子表达式，每个‘()’之间的内容表示一个子表达式；
‘\’是一个转义字符，‘\\’表示扔掉第二个‘\’的转义特性，‘\w+’表示匹配一个或多个单词，‘+’表示重复一次或者多次，
因此第一个子表达式的意思就是匹配一个或者多个单词；接着看第二个子表达式，‘|’表示选择，出现‘.’或者‘_’，
后面的‘?’表示该子表示出现一次或者零次，因此第二个子表示表示‘.’或‘_’出现不出现都匹配。
第三个子表达式表示出现一个单词，‘*’表示任意个字符
*/
bool is_email_valid(const string&email)
{
	const regex pattern("(\\w+)(\\.|)?(\\w*)@(\\w+)(\\.(\\w+))+");
	return regex_match(email, pattern);
}
int main()
{
	string email1 = "xuesen121415@gmail.com";
	string email2 = "374956586@qq.co.uk";
	string email3 = "marius.bancila@domain.com";
	string email4 = "marius@domin";
	cout << email1 << ":" << (is_email_valid(email1) ? "valid" : "invalid") << endl;
	cout << email2 << ":" << (is_email_valid(email2) ? "valid" : "invalid") << endl;
	cout << email3 << ":" << (is_email_valid(email3) ? "valid" : "invalid") << endl;
	cout << email4 << ":" << (is_email_valid(email4) ? "valid" : "invalid") << endl;
}
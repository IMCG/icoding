//regex/regextokeniter1.cpp
/*-1: all sub betweenm matcted regular(互补的)
   0: all matched.
   n: nth sub  inside the regular expressions.
*/
#include <string>
#include <regex>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	string data = "<person>\n"
		"<first>Nico</first>\n"
		"<last>Josuttis</last>\n"
		"</person>\n";
	regex reg("<(.*)>(.*)</(\\1)>");
	//iterate all matchs(using a regex_token_iteartor)
	sregex_token_iterator pos(data.cbegin(), data.cend(),
		reg,		//token separator
		{ 0, 2 });	//0:full 2:second substring
	sregex_token_iterator end;
	for (; pos != end; ++pos){
		cout << "match: " << pos->str() << endl;
	}
	cout << endl;

	string names = "nico, jim, helmut, paul, tim, john paul, rital";
	regex seq("[\t\n]*[,;.][ \t\n]*");//separate by ,;or.
	sregex_token_iterator p(names.cbegin(), names.cend(),
		seq,
		-1);//互补的
	sregex_token_iterator e;
	for (; p != e; ++p){
		cout << "name: " << *p << endl;
	}
}
//regex2.cpp
#include <iostream>
#include <regex>
#include <string>
using namespace std;
int main()
{
	//如果把换行符去掉，结果就会不一样。
	string data = "<person>\n"
		"<first>Nico</first>\n"
		"<last>Josuttis</last>\n"
		"</person>\n";
	regex reg("<(.*)>(.*)</(\\1)>");
	//iteate over all matchs
	auto pos = data.cbegin();//const begin() vs rbegin()
	auto end = data.cend(); //const iteators
	smatch m;
	for (; regex_search(pos, end, m, reg); pos = m.suffix().first){
		cout << "match: " << m.str() << endl;
		cout << "tag: " << m.str(1) << endl;
		cout << "value: " << m.str(2) << endl;
	}

}
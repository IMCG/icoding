//retex/regex4.cpp Regex Flags
#include <string>
#include <regex>
#include <iostream>
using namespace std;

int main()
{
	//case-insensitive find LaTeX index entries
	string pat1 = R"(\\.*index\{([^}]*)\})";//first capture group
	//2nd and 3rd capture group
	string pat2 = R"(\\.*index\{(.*)\}\{(.*)\})";
	regex pat(pat1 + "\n" + pat2,
		regex_constants::egrep | regex_constants::icase);

	//init string with chars from standord input:
	string data((istreambuf_iterator<char>(cin)),
		istreambuf_iterator<char>());
	//search and print matching index entries:
	smatch m;
	auto pos = data.cbegin();
	auto end = data.cend();
	for (; regex_search(pos, end, m, pat);pos=m.suffix().first){
		cout << "match: " << m.str() << endl;
		cout << " val: " << m.str(1) + m.str(2) << endl;
		cout << " see: " << m.str(3) << endl;
	}
}
//regex_constants 具体看 C++标准库

Regex ECMAScript Grammar

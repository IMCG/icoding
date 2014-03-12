//regex/regexreplace1.cpp
#include <iostream>
#include <string>
#include <regex>
#include <iterator>
using namespace std;
int main()
{
	string data = "<person>\n"
		"<first>Nico</first>\n"
		"<last>Josuttis</last>\n"
		"</person>\n";
	regex reg("<(.*)>(.*)</(\\1)>");
	//print data with replacement for matched patterns
	//R"(<$1 value="$2"/>)" equal to
	cout << regex_replace(data, reg,
		"<$1 value=\"$2\"/>") << endl;

	//same using [sed] syntax
	cout << regex_replace(data,
		reg,
		"<\\1 value=\"\\2\"/>",
		regex_constants::format_sed) << endl;

	//use iterator interfase 
	//-format_no_copy: don't copy characters that don't match
	//-format_first_only: replace only the first match found
	string res2;
	regex_replace(back_inserter(res2),
		data.begin(), data.end(),
		reg,
		"<$1 value=\"$2\"/>",
		regex_constants::format_no_copy |
		regex_constants::format_first_only);
	cout << res2;
}
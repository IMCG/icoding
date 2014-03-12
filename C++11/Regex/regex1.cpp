/*regex/regex1.cpp*/
#include <regex>
#include <iostream>
#include <string>
using namespace std;
void out(bool b){
	cout << (b ? "found" : "not found") << endl;
}
int main()
{
	regex reg1("<.*>.*</.*>");
	bool found = regex_match("<tag>value</tag>",//date
							reg1);				//grep
	out(found);
	/*R"(<(.*)>.*<(/\1)>)" equivalent to
	   "<(.*)>.*<(/\\1)>"
	   we can specify that the leading and the trailing tags
	   have to be the same charsq which is what the next 
	   staments demonstrate:
	*/
	regex reg2("<(.*)>.*<(/\\1)>");
	found = regex_match("<tag>value</tag>",
		reg2);
	out(found);
	//using grep syntax
	regex reg3("<\\(.*\\)>.*</\\1>", regex_constants::grep);
	found = regex_match("<tag>value</tag>", reg3);
	out(found);

	//use C-string as regx(needs explicit cast to regx)
	found = regex_match("<tag>value</tag>",
		regex("<(.*)>.*</\\1>"));
	out(found);
	cout << endl;

	//regex_match vs regex_search
	found = regex_match("XML tag: <tag>value</tag>",
		regex("<(.*)>.*</\\1>"));		//fail
	out(found);
	found = regex_match("XML tag: <tag>value</tag>",
		regex(".*<(.*)>.*</\\1>"));		//matchs
	out(found);
	found = regex_search("XML tag: <tag>value</tag>",
		regex("<(.*)>.*</\\1>"));		//matchs
	out(found);
	found = regex_search("XML tag: <tag>value</tag>",
		regex(".*<(.*)>.*</\\1>.*"));	//matchs
	out(found);

	return 0;
}
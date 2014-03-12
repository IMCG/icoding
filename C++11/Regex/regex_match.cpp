//regex_match:	matching return bool 验证是否匹配
#include<regex>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
int main()
{
	regex pattern("\\w+\\s*(\\(\\w+,\\d+\\)\\s*)*");
	//cout << pattern << endl;
	string str_1 = "chen (chen,0) (huan,1) (jiang,2)";
	string str_2 = "chen(chen,0)(huan,1)(jiang,2)";
	string str_3 = "chen";
	string str_4 = "(chen,0)(huan,1)(jiang,2)";
	string str_5 = "chen (chen,0) (huan,1)(jiang,2) chen";
	vector<string> strings;
	strings.push_back(str_1); 
	strings.push_back(str_2);
	strings.push_back(str_3); 
	strings.push_back(str_4);
	strings.push_back(str_5);
	for (int n = 0; n < 5; ++n)
		if (regex_match(strings[n], pattern))
			cout << strings[n] << " is matched" << endl;
		
		return 0;
	
}
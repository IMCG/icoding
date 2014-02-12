//regex_search：regex_match是验证是否完全匹配，
//而regex_search是从一大串string中找出匹配的一小段字符串
#include <iostream>
#include <regex>
#include <string>
using namespace std;
int main()
{
	regex pattern("\\d+");

	string str="chen123huan12345jiang12345";
	smatch mat;
	if(regex_search(str,mat,pattern))
			for(auto &m:mat)
				cout<<m<<endl;
	return 0;
}
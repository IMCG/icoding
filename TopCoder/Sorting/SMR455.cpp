//TheEncryptionDivTwo
#include "algostuff.h"
using namespace std;

map<char, char>mapping;
set<char>visited;
string encrypt(string message){
	
	int i = 0;
	for (auto& ch : message){
		if (!visited.count(ch)){
			visited.insert(ch);
			mapping[ch] = 'a' + i++;
		}
	}
	string res;
	for (auto& ch : message)
	{
		res += mapping[ch];
	}
	return res;
}
int main()
{
	string str;
	while (cin >> str){
		cout << encrypt(str) << "\n";
	}
	return 0;
}
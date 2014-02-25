//Return maximum occurring character in the input string
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
char MaxOccur(string &str)
{
	unordered_map<char, int>mapping;
	for (auto& i : str)
	{
		mapping[i]++;
	}
	int result = INT_MIN;
	char c;
	for (auto& i : mapping)
	{
		if (i.second > result){
			result = i.second;
			c = i.first;
		}
	}
	return c;
}
int main()
{
	string str = "test";
	cout << MaxOccur(str);
	return 0;
}

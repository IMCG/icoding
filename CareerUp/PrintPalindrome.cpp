//Print all palindromes of size greater than equal to 3 of a given string. (DP)
//可以用暴力解法（两个指针）
//必须考虑回文的长度。
//http://www.careercup.com/question?id=6413660553478144
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool ispalid(string&str)
{
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	str.erase(remove_if(str.begin(), str.end(), [](char c){return !isalnum(c); }), str.end());
	return equal(str.begin(), str.begin() + str.size() / 2, str.rbegin());
}
vector<string> allPalid(string&str)
{
	vector<string>result;
	string temp;
	for (size_t i = 0; i < str.size(); i++)
	{
		for (size_t j = 0; j <= i; j++)
		{
			temp = str.substr(j, i - j + 1);
			if (ispalid(temp))
				result.push_back(temp);
		}
	}
	return result;
}
int main()
{
	string str = "abcbafabcba";
	vector<string>result;
	result = allPalid(str);
	for (auto& s : result)
	{
		cout << s << endl;
	}
	return 0;
}

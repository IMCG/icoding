/*Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses. 

For example, given n = 3, a solution set is: 

"((()))", "(()())", "(())()", "()(())", "()()()" 

*/
//自己的版本有bug。以后修复。
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string>result;
		vector<string>temp;
		result.push_back("()");
		if (n == 1)
			return result;
		string str;
		for (int i = 1; i < n; i++)
		{
			for (auto& t : result)
			{
				for (size_t j = 0; j <= t.size(); j++)
				{
					str = t.insert(j, "()");
					if (find(temp.begin(), temp.end(), str) != temp.end())
						temp.push_back(str);
				}
			}
			swap(result, temp);
			temp.clear();
		}
		return result;
	}
};
int main()
{
	Solution s;
	vector<string> test = s.generateParenthesis(3);

	for (auto& i : test)
	{
		cout << i << endl;
	}
	return 0;
}

//小括号串是个递归结构，（递归）
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		if (n == 0)return vector<string>(1, "");
		if (n == 1)return vector<string>(1, "()");

		vector<string>result;
		for (int i = 0; i < n; i++)
			for (auto& inner : generateParenthesis(i))
				for (auto& outer : generateParenthesis(n-i-1))
					result.push_back("(" + inner + ")" + outer);
		return result;
	}
};
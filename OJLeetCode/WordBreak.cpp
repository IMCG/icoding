/*Given a string s and a dictionary of words dict, determine if s can be segmented into 
a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/
#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
using namespace std;
//  20/21  test cases passed.递归调用。Time Limit Exceeded
class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		if (dict.find(s) != dict.end())
			return true;
		string str;
		for (size_t i = 0; i < s.size(); i++)
		{
			//不因该只从0开始
			str = s.substr(0, i);
			if (dict.find(str) != dict.end())
			{
				if(wordBreak(s.substr(i), dict))
					return true;
			}
		}
		return false;
	}
};

//DP.状态为f(i).表示s[0,i]是否可以分词
class Solution{
public:
	bool wordBreak(string s, unordered_set<string>&dict){
		//长度为n,由n+1个隔板
		if(dict.find(s)!=dict.end())
		    return true;
		vector<bool> f(s.size() + 1, false);
		f[0]=true;
		for (size_t  i = 1; i <= s.size(); i++)
		{
			for (int j = i-1; j >= 0; j--)
			{
				if (f[j] && dict.find(s.substr(j, i - j)) != dict.end()){
					f[i] = true;
					break;
				}
			}
		}
		return f[s.size()];
	}
};


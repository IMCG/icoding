/*For Example:

Input string1: “this is a test string”
Input string2: “tist”
Output string: “t stri”
*/
//Method 1 ( Brute force solution )
a) Generate all substrings of string1 (“this is a test string”)
b) For each substring, check whether the substring contains all characters of string2 (“tist”)
c) Finally print the smallest substring containing all characters of string2.

//Method 2 ( Efficient Solution )   尺规法
1) Build a count array count[] for string2. The count array stores counts of characters.
count['i'] = 1
count['t'] = 2
count['s'] = 1

//
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution{
public:
	string MinWindow(string S, string T)
	{
		if (S.empty())return "";
		if (S.size() < T.size())return "";

		const int ASCII_MAX = 256;
		int appear[ASCII_MAX];
		int expect[ASCII_MAX];
		fill(appear, appear + ASCII_MAX, 0);
		fill(expect, expect + ASCII_MAX, 0);

		for (auto& ch : T) expect[ch]++;
		int minWidth = INT_MAX, min_start = 0;//大小 起点
		int wnd_start = 0;
		int count = 0;//查找了一个T
		//扩展尾
		for (size_t wnd_end = 0; wnd_end < S.size(); wnd_end++)
		{
			if (expect[S[wnd_end]]>0){
				appear[S[wnd_end]]++;
				//注意这里
				if (appear[S[wnd_end]] <= expect[S[wnd_end]])
					count++;
			}
			if (count == T.size())
			{
				//收缩头
				while (appear[S[wnd_start]]>expect[S[wnd_start]]
					||expect[S[wnd_start]]==0){
					appear[S[wnd_start]]--;
					wnd_start++;
				}
				if (minWidth > (wnd_end - wnd_start + 1)){
					minWidth = wnd_end - wnd_start + 1;
					min_start = wnd_start;
				}
			}
		}
		if (minWidth == INT_MAX) return"";
		else return S.substr(min_start, minWidth);
	}
};
int main()
{
	string dst = "this is a test string";
	string src = "tist";
	Solution s;
	cout<<s.MinWindow(dst, src);
}

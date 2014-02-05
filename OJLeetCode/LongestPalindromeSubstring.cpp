//Longest Palindromic Substring最长回文子串
//http://leetcode.com/2011/11/longest-palindromic-substring-part-i.html
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//学习DP;
/*		true						i=j;
f(i,j)= s[i]=s[j]					j=i+1;
		s[i]=s[j]&&f(i+1,j-1)		j>i+1;
	最后两个条件（i-j<2)||f[j+1][i-1]; 
*/
string LongestPalindrome(string const&s)
{
	const size_t n = s.size();
	//bool f[n][n];
	//fill_n(&f[0][0], n*n, false);
	//用vector会超时
	vector<vector<bool>>f(n,vector<bool>(n,false));
	size_t max_len = 1, start = 0;

	for (size_t i = 0; i < s.size(); i++)
	{
		f[i][i] = true;
		for (size_t j = 0; j < i; j++)
		{
			f[j][i] = (s[j] == s[i] && (i - j < 2 || f[j + 1][i - 1]));
			if (f[j][i] && max_len < (i - j + 1))
			{
				max_len = i - j + 1;
				start = j;
			}
		}
	}
	return s.substr(start, max_len);
}
string LongestPalindromeDP(string s)
{
	int n = s.length();
	int longestBegin = 0;
	int maxlen = 1;
	bool table[1000][1000] = { false };
	for (int i = 0; i < n; i++)
		table[i][i] = true;
	for (int i = 0; i < n - 1; i++)
	{
		if (s[i] == s[i + 1]){
			table[i][i + 1] = true;
			longestBegin = i;
			maxlen = 2;
		}
	}
	for (int len = 3; len < n; len++)
	{
		for (int i = 0; i < n-len+1; i++)
		{
			int j = i + len - 1;
			if (s[i] == s[j] && table[i + 1][j - 1])
			{
				table[i][j] = true;
				longestBegin = i;
				maxlen = len;
			}
		}
	}
	return s.substr(longestBegin, maxlen);
}
//expanding a palindrome around its center
// there are only 2N-1 such centers.
string expandAroundCenter(string s, int c1, int c2)
{
	int l = c1, r = c2;
	int n = s.length();
	while (l >= 0 && r <= n - 1 && s[l] == s[r]){
		l--;
		r++;
	}
	return s.substr(l + 1, r - l - 1);
}
string LongestPalindromeSimple(string const&s)
{
	int n = s.length();
	if (n == 0)return "";
	string longest = s.substr(0, 1);//a single char
	for (int i = 0; i < n-1; i++)
	{
		string p1 = expandAroundCenter(s, i, i);
		if (p1.length()>longest.length())
			longest = p1;
		string p2 = expandAroundCenter(s, i, i + 1);
		if (p2.length() > longest.length())
			longest = p2;
	}
	return longest;
}
int main()
{
	const string s = "343abcddcba234";
	string test = LongestPalindromeDP(s);
	cout << test;
}



//备忘录法
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
typedef string::const_iterator Iterator;
namespace std{
	template<>
	struct hash<pair<Iterator, Iterator>>{
		size_t operator()(pair<Iterator, Iterator>const&p)const{
			return ((size_t)&(*p.first)) ^ ((size_t)&(*p.second));
		}
	};
}
class Solution{
public:
	string LongestPalindrome(string const&s){
		cache.clear();
		return cachedLongestPalindrome(s.begin(), s.end());
	}
private:
	unordered_map<pair<Iterator, Iterator>, string> cache;
	string longestPalindrome(Iterator first, Iterator last){
		size_t length = distance(first, last);
		if (length < 2)return string(first, last);
		
		auto s = cachedLongestPalindrome(next(first), prev(last));

		if (s.length() == length - 2 && *first == *prev(last))
			return string(first, last);

		auto s1 = cachedLongestPalindrome(next(first), last);
		auto s2 = cachedLongestPalindrome(first, prev(last));
		//return max(s,s1,s2)
		if (s.size()>s1.size()) return s.size() > s1.size() ? s : s1;
		else return s1.size() > s2.size() ? s1 : s2;
	}
	string cachedLongestPalindrome(Iterator first, Iterator last){
		auto key = make_pair(first, last);
		auto pos = cache.find(key);

		if (pos != cache.end())return (*pos).second;
		else return cache[key] = longestPalindrome(first, last);
	}
};
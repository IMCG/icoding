/*A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/
//dfs  ----->dp
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
	int numDecodings(string s) {
		this->total = 0;
		dfs(0, s);
		return total;
	}
private:
	int total;
	void dfs(int begin,string &s)
	{
		const int m = s.length();
		if (begin == m){
			total++;
			return;
		}
		dfs(begin + 1, s);
		if (static_cast<int>(s[begin]) < 3 && 
			static_cast<int>(s[begin + 1]) < 7&&(begin+1) < m){
			dfs(begin + 2, s);
		}
		//return;
	}
};
int main()
{
	Solution s;
	string str = "1";
	cout << s.numDecodings(str);

	return 0;
}
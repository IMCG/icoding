/*Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/
class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>>result;
		const int m = s.length();
		if (m == 0)return result;
		vector<string>cur;
		part(result, cur, s, 0);
		return result;
	}
private://深度优先    combination sum>>
	void part(vector<vector<string>>&result, vector<string>&cur, 
		string s,int start)
	{
		if (start==s.size()){
			result.push_back(cur);
			return;
		}
		for ( size_t i = start; i < s.size(); i++){
			if (isPalind(s, start, i)){
				cur.push_back(s.substr(start, i - start + 1));
				part(result, cur, s, i + 1);
				cur.pop_back();//回溯
			}
		}
	}
	//使用区间，而不是用子串
	bool isPalind(string &s,int start,int end){
		while (start < end){
			if (s[start] != s[end])return false;
			start++;
			end--;
		}
		return true;
	}
};
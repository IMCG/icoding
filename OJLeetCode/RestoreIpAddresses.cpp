/*Given a string containing only digits, restore it by returning all 
possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string>result;
		string cur;
		dfs(s, 0, 0, cur, result);
		return result;
	}
private:
	void dfs(string s,size_t start,size_t step,
		string cur,vector<string>&result){
		if (start == s.size() && step == 4){
			cur.resize(cur.size() - 1);//去除 。
			result.push_back(cur);
			return;
		}
		if (s.size() - start > (4 - step) * 3)
			return;
		if (s.size() - start < (4 - step))
			return;
		int num = 0;
		for (size_t i = start; i < start + 3; i++){
			num = num * 10 + (s[i] - '0');
			if (num <= 255){
				cur += s[i];
				dfs(s, i + 1, step + 1, cur + '.', result);
			}
			if (num == 0)break;
		}
	}
};
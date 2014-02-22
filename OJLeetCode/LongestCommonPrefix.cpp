//Write a function to find the longest common prefix string amongst an array 
//of strings.
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.size()==0)
            return ""; 
        string result = strs[0];
		for (auto& a : strs){
			result = CommonPrefix(result, a);
		}
		return result;
    }
    string CommonPrefix(string&s, string&t){
		int m = s.length();
		int n = t.length();
		int len = max(m, n);
		int i = 0;
		while (s[i] == t[i] && i < len)
			i++;
		return s.substr(0, i);
	}
};
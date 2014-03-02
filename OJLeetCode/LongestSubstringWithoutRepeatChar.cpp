/*Given a string, find the length of the longest substring without 
repeating characters. For example, the longest substring without 
repeating letters for "abcabcbb" is "abc",which the length is 3. 
For "bbbbb" the longest substring is "b", with the length of 1.
*/

//Pay attention when moving the 'start' pointer forward.
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		bool exist[256];
		memset(exist, false, sizeof(exist));
		int res = 0;
		int start = 0, end = 0, N = s.size();
		while (end < N && start + res < N)
		{
			if (!exist[s[end]])
				exist[s[end++]] = true;
			else
				exist[s[start++]] = false;
			res = max(end - start, res);
		}
		return res;
	}
};
//? bug 考虑错误
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0)return 0;
		int longest = 0;
		int length = 0;
		vector<char>t;
		for (auto& c : s)
		{
			if (t.size() == 0){
				t.push_back(c);
			}
			else if (find(begin(t), end(t), c) == t.end()){
				t.push_back(c);
			}
			else{
				length = t.size();
				longest = max(longest,length);
				t.clear();
				t.push_back(c);
			}
		}
		return max(longest, (int)t.size());
    }
};
/*Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/
//DP
// LeetCode, Interleaving String
// 二维动规，时间复杂度O(n^2)，空间复杂度O(n^2)
class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s3.length() != s1.length() + s2.length())
			return false;
		vector<vector<bool>> f(s1.length() + 1,
			vector<bool>(s2.length() + 1, true));
		for (size_t i = 1; i <= s1.length(); ++i)
			f[i][0] = f[i - 1][0] && s1[i - 1] == s3[i - 1];
		for (size_t i = 1; i <= s2.length(); ++i)
			f[0][i] = f[0][i - 1] && s2[i - 1] == s3[i - 1];
		for (size_t i = 1; i <= s1.length(); ++i)
		for (size_t j = 1; j <= s2.length(); ++j)
			f[i][j] = (s1[i - 1] == s3[i + j - 1] && f[i - 1][j])
			|| (s2[j - 1] == s3[i + j - 1] && f[i][j - 1]);
		return f[s1.length()][s2.length()];
	}
};
//递归 TLE
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        return isInterleaveRe(s1.c_str(), s2.c_str(), s3.c_str());
    }
bool isInterleaveRe(const char *s1, const char *s2, const char *s3)
    {
        if (*s1 == '\0' && *s2 == '\0' && *s3 == '\0') return true;
        if (*s3 == '\0') return false;
        if (*s1 == '\0') return strcmp(s2, s3) == 0;
        if (*s2 == '\0') return strcmp(s1, s3) == 0;

        return *s1 == *s3 && isInterleaveRe(s1+1, s2, s3+1) || 
               *s2 == *s3 && isInterleaveRe(s1, s2+1, s3+1);
    }
};

//83/100 通过。 考虑不全面
/*Input:	"aabc", "abad", "aabadabc"
Output:	false
Expected:	true
*/
class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.length() + s2.length() != s3.length())
			return false;
		char a, b, c;
		while (s1.length() && s2.length()){
			a = s1.back();
			b = s2.back();
			c = s3.back();
			if (a == c){
				s1.pop_back();
				s3.pop_back();
			}
			else if(b==c){
				s2.pop_back();
				s3.pop_back();
			}
			else
				return false;
		}
		if (s1.length())
			return s1 == s3;
		else
			return s2 == s3;
	}
};
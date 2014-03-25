//可以求出全部Interleaving  然后看是否在其中
//有重复的时候  DP
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


//依次遍历 注意:当有重复的时候就会fail
#include <stdio.h>
 
// Returns true if C is an interleaving of A and B, otherwise
// returns false
bool isInterleaved (char *A, char *B, char *C)
{
    // Iterate through all characters of C.
    while (*C != 0)
    {
        // Match first character of C with first character of A,
        // If matches them move A to next 
        if (*A == *C)
            A++;
 
        // Else Match first character of C with first character of B,
        // If matches them move B to next 
        else if (*B == *C)
            B++;
  
        // If doesn't match with either A or B, then return false
        else
            return false;
         
        // Move C to next for next iteration
        C++;
    }
 
    // If A or B still have some characters, then length of C is smaller 
    // than sum of lengths of A and B, so return false
    if (*A || *B)
        return false;
 
    return true;
}
 
// Driver program to test above functions
int main()
{
    char *A = "AB";
    char *B = "CD";
    char *C = "ACBG";
    if (isInterleaved(A, B, C) == true)
        printf("%s is interleaved of %s and %s", C, A, B);
    else
        printf("%s is not interleaved of %s and %s", C, A, B);
 
    return 0;
}
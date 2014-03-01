/*Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

class Solution {
public:
        int minCut(string s) {
		const int n = s.size();
		int f[n + 1];
		bool p[n][n];
		fill_n(&p[0][0], n*n, false);
		//the worst case is cutting by each char
		for (int i = 0; i <= n; i++)
			f[i] = n - i - 1;//last one f[n]=-1
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = i; j < n; j++){
				if (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1])){
					p[i][j] = true;
					f[i] = min(f[i], f[j + 1] + 1);
				}
			}
		}
		return f[0];
    }
};

class Solution {
public:
	int minCut(string s) {
		int N = s.size();
		vector<bool>isP(N);
		vector<int>dp(N);
		dp[0] = 0;
		for (int i = 1; i < N; i++)
		{
			isP[i] = true;
			dp[i] = dp[i - 1] + 1;
			for (int j = 0; j < i; ++j)
			{
				isP[j] = (s[i] == s[j]) ? isP[j + 1] : false;
				if (isP[j])
					dp[i] = (j == 0) ? 0 : min(dp[i], dp[j - 1] + 1);
			}
		}
		return dp[N - 1];
	}
};
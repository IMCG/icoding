/*Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        const int m = word1.length();
		const int n = word2.length();
		//默认初值的时候要注意是否要initial为INF
		vector<vector<int>>dp(m + 1, vector<int>(n + 1, -1));
		for (int i = 0; i <= m; i++)
			dp[i][0] = i;
		for (int j = 0; j <= n; j++)
			dp[0][j] = j;
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				//dp[i][j]长度分别为i，j是最小值.所以word1[i-1]....(后面一定要加括号)
				int rep = dp[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]);
				int del = 1 + dp[i][j - 1];
				int ins = 1 + dp[i - 1][j];
				dp[i][j] = min(rep, min(del, ins));

				//if (word2[i-1] == word1[j-1])
    			//	dp[i][j] = dp[i-1][j-1];
    			//else
    			//	dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
			}		
		}
		return dp[m][n];
    }
};
//递归方法。
class Solution {
public:
	int minDistance(string word1, string word2) {
		const int m = word1.length();
		const int n = word2.length();
		return Recursion(word1, word2, m, n);
	}
	int Recursion(string X, string Y, int m, int n)
	{
		if (m == 0 && n == 0)
			return 0;
		if (m == 0)
			return n;
		if (n == 0)
			return m;
		// Recurse  
		int left = Recursion(X, Y, m - 1, n) + 1;
		int right = Recursion(X, Y, m, n - 1) + 1;
		int corner = Recursion(X, Y, m - 1, n - 1) + (X[m - 1] != Y[n - 1]);
		return	min(left, min(right, corner));
	}
};
//备忘录 
const int MAX = 10000;
int dp[MAX][MAX];
class Solution{
public:
	int minDistance(string word1, string word2){
		int n = word1.length();
		int m = word2.length();
		memset(dp, 0, sizeof(dp));
		return Recursion(word1, word2, n, m);
	}
	int Recursion(string X, string Y, int n, int m){
		if (dp[n][m] > 0)
			return dp[n][m];
		if (n == 0 || m == 0)
			return dp[n][m] = 0;
		if (n == 0)
			return dp[n][m] = m;
		if (m == 0)
			return dp[n][m] = n;
		//别忘了加1
		int left = Recursion(X, Y, n - 1, m) + 1;
		int right = Recursion(X, Y, n, m - 1) + 1;
		int corner = Recursion(X, Y, n - 1, m - 1) + (X[n - 1] != Y[m - 1]);
		return dp[n][m] = min(min(left, right), corner);
	}
};
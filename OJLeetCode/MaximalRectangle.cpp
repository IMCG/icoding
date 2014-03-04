/*Given a 2D binary matrix filled with 0's and 1's, find the largest 
rectangle containing all ones and return its area.*/

//正方形还行。
class Solution {
public:
	int maximalRectangle(vector<vector<int> > &matrix) {
		const int m = matrix.size();
		const int n = matrix[0].size();
		if (n == 0 || m == 0)return 0;
		vector<vector<int>>dp(m, vector<int>(n, 0));
		dp[0][0] = matrix[0][0];
		for (int i = 1; i < m; i++){
			dp[i][0] = (matrix[i][0] == 1) ? dp[i - 1][0] + 1 : 0;
		}
		for (int j = 1; j < n; j++){
			dp[0][j] = (matrix[0][j] == 1) ? dp[0][j - 1] + 1 : 0;
		}
		for (int i = 1; i < m; i++){
			for (int j = 1; j < n; j++){
				if (matrix[i][j] == 1){
					dp[i][j] = min(dp[i - 1][j],
						min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
				}
				else
					dp[i][j] = 0;
			}
		}
		//return dp[m-1][n-1]
	}
};


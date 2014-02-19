/*A robot is located at the top-left corner of a m x n grid (marked 'Start' in the 
diagram below).

The robot can only move either down or right at any point in time. The robot is trying
 to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>result(m, vector<int>(n, -1));
		result[0][0] = 1;
		for (int i = 1; i < m; i++)
			result[i][0] = 1;
		for (int j = 1; j < n; j++)
			result[0][j] = 1;
		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++)
				result[i][j] = result[i][j - 1] + result[i - 1][j];
		return result[m - 1][n - 1];
    }
};
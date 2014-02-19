/*Given a m x n grid filled with non-negative numbers, find a path 
from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/
class Solution {
public:
	int minPathSum(vector<vector<int> > &grid) {
		const int m = grid.size();
		const int n = grid[0].size();
		vector<vector<int>>result(m, vector<int>(n, 0));
		//第一行，第一列只能从相应的地方递推.注意初始情况
		result[0][0] = grid[0][0];
		for (int i = 1; i < m; i++)
			result[i][0] = result[i-1][0] + grid[i][0];
		for (int j = 1; j < n; j++)
			result[0][j] = result[0][j - 1] + grid[0][j];
		for (int i = 1; i<m; i++)
		{
			for (int j = 1; j<n; j++)
			{
				result[i][j] = min(result[i][j - 1], result[i - 1][j]) + grid[i][j];
			}
		}
		return result[m - 1][n - 1];
	}
};

//备忘录法
class Solution
{
public:
	int minPathSum(vector<vector<int>>&grid){
		const int m=grid.size();
		const int n=grid[0].size();
		//必须初始值为-1.因为后面是>=0.
		this->f=vector<vector<int>>(m,vector<int>(n,-1));
		return dfs(grid,m-1,n-1);
	}
private:
	vector<vector<int>> f;//缓存
	int dfs(const vector<vector<int>>&grid,int x,int y){
		if(x<0 || y<0 )return INT_MAX;//越界
		if(x==0 && y==0 )return grid[0][0];

		return min(getOrUpdata(grid,x-1,y),
				getOrUpdata(grid,x,y-1))+grid[x][y];
	}
	int getOrUpdata(const vector<vector<int>>&grid,int x,int y){
		if(x<0 || y<0)return INT_MAX;
		if(f[x][y]>=0)return f[x][y];
		else return f[x][y]=dfs(grid,x,y);
	}
};

//滚动数组。
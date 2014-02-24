//Egg Dropping Puzzle
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//当从第x层丢下来的时候，两种情况：破或不破。
//Recursive n eggs,k floors
int eggDrop(int n, int k)
{
	if (k == 1 || k == 0)
		return k;
	if (n == 1)
		return k;
	int Min = INT_MAX;
	int res;
	//从第一层到底K层。 
	for (int x = 1; x <= k; x++)
	{
		res = max(eggDrop(n - 1, x - 1), eggDrop(n, k - x));
		if (res < Min)
			Min = res;
	}
	return Min + 1;
}
//DP
int eggDrop1(int n, int k)
{
	vector<vector<int>>dp(n + 1, vector<int>(k + 1,INT_MAX));
	int res;
	for (int i = 1; i <= n; i++){
		dp[i][1] = 1;
		dp[i][0] = 0;
	}
	for (int j = 1; j <= k; j++)
		dp[1][j] = j;

	for (int i = 2; i <= n; i++){
		for (int j = 2; j <= k; j++){
			for (int x = 1; x <= j; x++){
				res = 1 + max(dp[i - 1][x - 1], dp[i][j - x]);
				dp[i][j] = min(res, dp[i][j]);	
			}
		}
	}
	return dp[n][k];
}
int main()
{
	int n = 2, k = 10;
	cout << eggDrop1(n, k);
	return 0;
}
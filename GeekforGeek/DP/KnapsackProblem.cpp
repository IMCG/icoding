//背包问题
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
//Returns the maximum value		直接递归。
int knapSack(int W, int wt[], int val[], int n)
{
	//Base Case
	if (n == 0 || W == 0)
		return 0;
	//If weight of the nth > W,then excluded.
	if (wt[n - 1] > W)
		knapSack(W, wt, val, n - 1);
	else//可以包括也可以不包括
		return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),
				knapSack(W, wt, val, n - 1));
}
//子问题重叠
int knapSack1(int W, int wt[], int val[], int n)
{
	int i, w;
	vector<vector<int>>dp(n + 1, vector<int>(W + 1));
	for (i = 0; i <= n; i++)
	{
		for (w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
				dp[i][w] = 0;
			else if (wt[i - 1] <= w)
				dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
			else
				dp[i][w] = dp[i - 1][w];
		}
	}
	return dp[n][W];
}
int main()
{
	int val[] = { 60, 100, 120 };
	int wt[] = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(val) / sizeof(val[0]);
	cout << knapSack1(W, wt, val, n);

	return 0;
}
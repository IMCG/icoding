/*Given a value N, if we want to make change for N cents, and we have 
infinite supply of each of S = { S1, S2, .. , Sm} valued coins, how many 
ways can we make the change? The order of coins doesn’t matter.
*/
#include <vector>
#include <iostream>
using namespace std;
/*Divide all set solutions in two sets
*1.do not contain mth coin
*2.cotain at least one Sm.
*/
//Returns the count of ways to get sum n
int count(int S[], int m, int n)
{
	if (n == 0)
		return 1;
	if (n < 0)
		return 0;
	//m总会减少到0
	if (m <= 0 && n >= 1)
		return 0;
	//? includes S[m-1]
	return count(S, m - 1, n) + count(S, m, n - S[m - 1]);
}
//Dp
int count1(int S[], int m, int n)
{
	int x, y;
	vector<vector<int>>dp(n + 1, vector<int>(m));
	for (int i = 0; i < m; i++)
		dp[0][i] = 1;
	// Fill rest of the dp enteries in bottom up manner
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// Count of solutions including S[j]
			x = (i - S[j] >= 0) ? dp[i - S[j]][j] : 0;
			// Count of solutions excluding S[j]
			y = (j >= 1) ? dp[i][j - 1] : 0;
			// total count
			dp[i][j] = x + y;
		}
	}
	return dp[n][m - 1];
}
int main()
{
	int arr[] = { 1, 2, 3 };
	int m = 3;
	cout << count(arr, m, 4);
	return 0;
}
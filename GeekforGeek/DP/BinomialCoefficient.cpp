/* C(n, k) = C(n-1, k-1) + C(n-1, k)
   C(n, 0) = C(n, n) = 1
*/
#include <iostream>
using namespace std;

//Recursion
int binomialCoeff(int n,int k)
{
	//Base Case
	if(k==0 || k==n)
		return 1;
	return binomialCoeff(n-1,k-1)+binomialCoeff(n-1,k);
}
//DP
int binomialCoeff1(int n,int k)
{
	int dp[n+1][k+1];
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= min(k,j); ++j)
		{
			if(j==0||j==i)
				dp[i][j]=1;
			else
				dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
		}
	}
	return dp[n][k];
}
//滚动数组
int binomialCoeff2(int n,int k)
{
	int dp[k+1];
	dp[0]=1;
	for(int i = 1;i <= n; i++)
	{
		for(j = min(i,k);j > 0;j--)
		{
			dp[j]=dp[j]+dp[j-1];
		}
	}
	return dp[k];
}
//备忘录
int binomialCoeff3(int n,int k)
{
	if(k==0 || k==n)
		return 1;
	return dp[n-1][k-1]+dp[n-1][k];
}
int getUpdate(int n,int k)
{
	if(dp[n][k]>0)return dp[n][k];
	else dp[n][k]=binomialCoeff3(n,k);
}


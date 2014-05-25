/*当n为奇数时，第一个数必须为1，此时f(n)=f(n-1)；当n为偶数时，分两种情况讨论，
若第一个数为1，则f(n)=f(n-1)，若第一个数不为奇数，则所有数都不为奇数，提出一个公因子2出来，
就是f(n/2)，所以，f(n)=f(n-1)+f(n/2)
odd even
*/
#include <stdio.h>
//用于最后数据处理
const int mod = 1e9;
const int MAX_N = 1000005;

int dp[MAX_N];
int main()
{
	int n, i;
	//因多次输入先打表
	dp[1] = 1, dp[2] = 2;
	for (int i = 3; i < MAX_N;++i)
		dp[i] = (i & 1 ? dp[i - 1] : (dp[i - 1] + dp[i >> 1]) % mod);

	while (~scanf("%d", &n)){
		printf("%d\n", dp[n]);
	}
	return 0;
} 
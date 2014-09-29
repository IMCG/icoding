//DP 从下往上走 AC
//1196K	157MS
//POJ 1163一样的题目
#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

#define MAX_N 360
int map[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];
int N;
void solve(){
	
	for (int i = N - 1; i >= 0; i--){
		for (int j = 0; j <= i; ++j){
			if (i == N - 1)
				dp[i][j] = map[i][j];
			dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + map[i][j];
		}
	}
	printf("%d\n", dp[0][0]);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE

	cin >> N;
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < i + 1; j++){
			cin >> map[i][j];
		}
	}
	solve();

	return 0;
}
//用压缩数组  700K	125MS
int dp[2][MAX_N];
int N;
void solve(){
	
	for (int i = N - 1; i >= 0; i--){
		for (int j = 0; j <= i; ++j){
			if (i == N - 1)
				dp[i&1][j] = map[i][j];
			dp[i&1][j] = max(dp[(i + 1)&1][j], dp[(i + 1)&1][j + 1]) + map[i][j];
		}
	}
	printf("%d\n", dp[0][0]);
}
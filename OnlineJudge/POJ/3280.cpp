//Cheapest Palindrome
//POJ 3280
//想递推关系再写代码..
//dp[i][j]表示将i--j变成回文串的最小代价return dp[0][M-1]
#include <map>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#pragma warning(disable:4996)
#define MAX_M 2005
int cost[28];
string str;
int N, M;
//dp[i][j] 使[i,j)子串变为palind min_cost
int dp[MAX_M][MAX_M];
int main(){
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	cin >> N >> M;
	cin >> str;
	char t;
	int a, d;
	for (int i = 0; i < N; ++i){
		cin >> t >> a >> d;
		//对于一个添加或删除都回文的话,当然去min
		cost[t - 'a'] = min(a, d);
	}
	//循环方向趋于dp[0][M-1]
	for (int i = M - 1; i >= 0; --i){
		for (int j = i + 1; j < M; ++j){
			//比i,j 分别少一个首字符，尾字符
			dp[i][j] = min(dp[i + 1][j] + cost[str[i] - 'a'],
				dp[i][j - 1] + cost[str[j] - 'a']);
			if (str[i] == str[j])
				dp[i][j] = min(dp[i][j],dp[i + 1][j - 1]);
		}
	}
	cout << dp[0][M - 1] << "\n";
	return 0;
}
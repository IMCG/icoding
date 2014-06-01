//dp 想状态，
// 只能@继续本棵树d[i-1][j]@另一颗树d[i-1][j-1]
//d[i][j]表示第i分钟移动j次最多接到苹果树
//第i分钟到某颗树下有 		----2种状态转换-----
// d[i-1][j-1](从另一棵树) d[i-1][j](还是本棵树)
// +count() 和j的奇偶性有关.(j&1)=a[i]==1?1:0  2-a[i]
// 							else a[i]==2?1:0   a[i]-1						
#include <iostream>
#include <algorithm>
using namespace std;

#pragma warning(disable:4996)
#define MAX_T 1005
#define MAX_W 35
int d[MAX_T][MAX_W];

int t, w;
int a[MAX_T];
void solve(){
	if (t < w)w = t;
	for (int i = 0; i <= w; ++i)d[0][i] = 0;
	//d[i][j]掉了i次动了j次最大值
	for (int i = 1; i <= t; ++i){
		d[i][0] = d[i - 1][0] + 2 - a[i];
		for (int j = 1; j <= w; ++j){
			d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]);
			if (j & 1)
				d[i][j] += a[i] - 1;
			else
				d[i][j] += 2 - a[i];
		}
	}
	// int count = 0;
	// for (int i = 0; i <= w; ++i){
	// 	count = max(count, d[t][i]);
	// }
	// cout << count << "\n";
	cout << d[t][w] << "\n";
}
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	cin >> t >> w;
	//从1开始
	for (int i = 1; i <= t;++i)
		cin >> a[i];
	solve();
	return 0;
}

//想递推关系的时候不知道怎么判断在那棵树下
//@ j的奇偶形可以告诉我们

//@ 亦可以通过一个数组记录当前位置
// for ( i = 0; i < 31; ++i)    P[i] = ((i % 2 == 0)? 1 : 2 );  
// 然后初始化dp[i][0] = dp[i-1][0] + (T[i] == P[0] ? 1 : 0); 
// 递推dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + (T[i] == P[j] ? 1 : 0);
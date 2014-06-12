//多重背包 二维  Good    背包个数在第2，3层循环不同。
//count count_if 在累计的用途
#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
#define forn(i,n) for(int i=0;i<n;++i)
#define maxn 105
#define maxm 100005
using namespace std;

int w[maxn], c[maxn];
bool d[maxn][maxm];
int n, m;
//@1
//dp[i][j]i个物体是否能组成j。。DP问题值记录bool会损失不少信息
void dp(){
	d[0][0] = true;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= m; ++j)
			for (int k = 0; k <= c[i]; ++k)
				d[i + 1][j] |= d[i][j - k* w[i]];
	//好用处		
	int res = count(d[n] + 1, d[n] + 1 + m, true);
	printf("%d\n", res);
}
//@2 思考
//dp[i][j]用前i种硬币凑成j时第i种硬币最多能剩余多少
void dp(){
	memset(d, -1, sizeof(d));
	d[0][0] = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= m; ++j){
				if (d[i][j] >= 0)
					d[i + 1][j] = c[i];
				else if (w[i]>j || d[i + 1][j - w[i]] <= 0)//用一个就超出，或者连小于j的都配不出
					d[i + 1][j] = -1;
				else
					d[i + 1][j] = d[i + 1][j - w[i]] - 1;
			}
	int answer = count_if(d[n] + 1, d[n] + 1 + m, 
		bind2nd(greater_equal<int>(), 0)); // 总额0不算在答案内
	cout << answer << endl;
}
//@3一维数组
int d[maxm];
void dp(){
	memset(d, -1, sizeof(d));
	d[0] = 0;
	forn(i, n)
		forn(j, m + 1)
		if (d[j] >= 0)d[j] = c[i];
		else if (j < w[i] || d[j - w[i]] <= 0)d[j] = -1;
		else d[j] = d[j - w[i]] - 1;

		int answer = count_if(d + 1, d + 1 + m, 
			bind2nd(greater_equal<int>(), 0)); 
		cout << answer << endl;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt","r",stdin);
#endif // !ONLINE_JUDGE
	while (scanf("%d %d", &n, &m)){
		if (n == 0 && m == 0)
			return 0;
		forn(i, n)scanf("%d", &w[i]);
		forn(i, n)scanf("%d", &c[i]);
		dp();
	}
	return 0;
}




//多重背包 滚动数组 TLE  k在第三层
void dp(){
	memset(d, 0, sizeof(d));
	d[0] = 1;	
	for (int i = 0; i < n; ++i)
		for (int j = m; j >= 1; --j)
			for (int k = 0; k <= c[i] && k*w[i] <= j; ++k)
				d[j] |= d[j - k* w[i]];
	int res = count(d + 1, d + 1 + m, true);
	printf("%d\n", res);
}
//k在第二层
void dp(){
	memset(d, 0, sizeof(d));
	d[0] = 1;
	for (int i = 0; i < n; ++i)
		for (int k = 0; k < c[i]; ++k)
			for (int j = m; j >= w[i]; --j)
				d[j] |= d[j - w[i]];
	int res = count(d + 1, d + 1 + m, true);
	printf("%d\n", res);
}
//多重背包 好的分拆(只是递推关系变了一下)   AC  
void ZeroOne(bool d[], int c){
	for (int i = m; i >= c; --i)
		d[i] |= d[i - c];
}
void Complete(bool d[], int c){
	for (int i = c; i <= m; ++i)
		d[i] |= d[i - c];
}
void dp(){
	memset(d, 0, sizeof(d));
	d[0] = 1;
	forn(i, n){
		if (w[i] * c[i] >= m){
			Complete(d, w[i]);
		}
		else{
			int k = 1;
			while (k < c[i]){
				ZeroOne(d, k*w[i]);
				c[i] -= k;
				k <<= 1;
			}
			ZeroOne(d, c[i]*w[i]);
		}
	}
	int ans = count(d + 1, d + 1 + m, true);
	cout << ans << "\n";
}

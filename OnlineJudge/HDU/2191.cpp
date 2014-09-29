//利用01背包
#include <iostream>
#include <algorithm>
using namespace std;
#define forn(i,n) for(int i=0;i<n;++i)
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b)
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define maxn 105
#pragma warning(disable:4996)
int W, N;
int w[maxn], v[maxn], c[maxn];
int d[maxn];
void zero_one_knapsack(int d[], int i, int c){
	int neww = c*w[i];
	int newv = c*v[i];
	for (int j = W; j >= neww; --j)
		d[j] = max(d[j], d[j - neww] + newv);
}
void unbounded(int d[], int i){
	for (int j = w[i]; j <= W; ++j)
		d[j] = max(d[j], d[j - w[i]] + v[i]);
}
//多重背包  注意次数为1，不为k。。。
void bound1(int d[], int i){
	forn(k, c[i])
		zero_one_knapsack(d, i, 1);
}
//好的拆分思想 利用01，和完全背包
void bound(int d[], int i){
	int k;
	if (c[i] * w[i] >= W){
		unbounded(d, i);
		return;
	}
	k = 1;
	while (k < c[i]){
		zero_one_knapsack(d, i, k);
		c[i] -= k;
		k *= 2;
	}
	zero_one_knapsack(d, i, c[i]);
}
void dp(){
	memset(d, 0, sizeof(d));
	forn(i, N)
		bound(d, i);
}
//..
void dp(){
	mem(d);
	forn(i, N)
		forn(k, c[i])
		for (int j = W; j >= w[i]; --j)
			d[j] = max(d[j], d[j - w[i]] + v[i]);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	int T;
	si(T);
	while (T--){
		sii(W, N);
		forn(i, N)siii(w[i], v[i], c[i]);
		dp();
		printf("%d\n", d[W]);
	}
	return 0;
}

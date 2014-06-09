//完全背包，要装满，数组初值
//POJ 1384
//HDU 1114
#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
const int maxn = 505;
const int maxw = 10005;
int N, W;
int w[maxn], v[maxn];
int d[maxw];

void dp(){
	int i;
	//要装满
	for (i = 0; i <= W; ++i)d[i] = INF;
	d[0] = 0;
	//i初值取决于下面输入。
	for (i = 0; i < N; ++i){
		for (int j = w[i]; j <= W; ++j)
			d[j] = min(d[j], d[j - w[i]] + v[i]);
	}
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt","r",stdin);
#endif // !ONLINE_JUDGE

	int i, T, E, F;
	scanf("%d",&T);
	while (T--){
		scanf("%d %d", &E, &F);
		W = F - E;
		scanf("%d", &N);
		for (i = 0; i < N; ++i)scanf("%d %d", &v[i], &w[i]);

		dp();
		if (d[W] == INF)
			printf("This is impossible.\n");
		else{
			printf("The minimum amount of money in the piggy-bank is %d.\n", d[W]);
		}
	}
	return 0;
}
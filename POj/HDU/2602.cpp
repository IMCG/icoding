//裸的0-1背包
//POJ 1384 完全背包
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

#define MAXN 1000
#define MAXN 1000
#define max(a,b) ((a)>(b)?(a):(b))
int N, W;
int w[MAXN + 1], v[MAXN + 1];

//2维数组
int f[MAXN + 1][MAXN + 1];

void dp(){
	int i, j;
	memset(f, 0, sizeof(f));
	for (i = 1; i <= N; ++i){
		for (j = 0; j <= W; ++j){
			f[i][j] = f[i - 1][j];
			if (j >= w[i]){
				const int temp = f[i - 1][j - w[i]] + v[i];
				f[i][j] = max(f[i][j], temp);
			}
		}
	}
}
//滚动数组
int d[MAXN + 1];
void dp(){
	int i, j;
	memset(d, 0, sizeof(d));
	//i初值取决于下面输入。
	for (i = 1; i <= N; ++i){
		for (j = W; j >= w[i]; --j){
			const int temp = d[j - w[i]] + v[i]; 
			d[j] = max(d[j], temp);
		}
	}
}
//DP数组再利用
int f[2][MAXN + 1];

void dp(){
	int i, j;
	memset(f, 0, sizeof(f));
	for (i = 1; i <= N; ++i){
		for (j = 0; j <= W; ++j){
			f[i&1][j] = f[(i - 1)&1][j];
			if (j >= w[i]){
				const int temp = f[(i - 1)&1][j - w[i]] + v[i];
				f[i&1][j] = max(f[i&1][j], temp);
			}
		}
	}
	//printf("%d\n", f[N&1][W]);
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	int i, T;
	scanf("%d", &T);
	while (T--){
		scanf("%d %d", &N, &W);
		for (i = 1; i <= N; ++i)scanf("%d", &v[i]);
		for (i = 1; i <= N; ++i)scanf("%d", &w[i]);

		dp();
		printf("%d\n", f[N][W]);
	}
	return 0;
}
//分别耗时
//46MS	4156K	688 B
//15MS	240K	609 B
//46MS	244K	695 B
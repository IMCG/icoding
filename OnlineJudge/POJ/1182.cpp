//并差集
//记住初始化，以及别把par  Rank弄串换了
#include <iostream>
using namespace std;
#pragma warning(disable:4996)

const int MAX_N = 50000;
int par[MAX_N];
int Rank[MAX_N];
int N, K;
//init
void init(int n){
	for (int i = 1; i <= n; ++i){
		par[i] = i;
		Rank[i] = 0;
	}
}
//find
int find(int x){
	return par[x] == x ? x : par[x] = find(par[x]);
}
bool same(int x, int y){
	return find(x) == find(y);
}
void unite(int x, int y){
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	if (Rank[x] < Rank[y]){
		par[x] = y;
	}
	else{
		par[y] = x;
		if (Rank[y] == Rank[x])
			Rank[x]++;
	}
}

//t为类型信息
int T[MAX_N], X[MAX_N], Y[MAX_N];

void solve(){
	//初始化并差集
	//x,x+N,x+2*N分别代表x-A,x-B,x-C;
	init(N * 3);

	int ans = 0;
	for (int i = 0; i < K; ++i){
		int t = T[i];
		//把输入变成[0,N-1]
		int x = X[i] - 1, y = Y[i] - 1;

		if (x < 0 || x >= N || y < 0 || y >= N){
			ans++;
			continue;
		}

		if (t == 1){
			//同类
			if (same(x, y + N) || same(x, y + 2 * N))
				ans++;
			else
			{
				unite(x, y);
				unite(x + N, y + N);
				unite(x + 2 * N, y + 2 * N);
			}
		}
		else{
			//x吃y
			if (same(x, y) || same(x, y + 2 * N))
				ans++;
			else
			{
				unite(x, y + N);
				unite(x + N, y + 2 * N);
				unite(x + 2 * N, y);
			}
		}
	}
	printf("%d\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE

	scanf("%d %d", &N, &K);
	for (int i = 0; i < K; ++i){
		scanf("%d %d %d", &T[i], &X[i], &Y[i]);
	}
	solve();
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif // !ONLINE_JUDGE
	return 0;
}


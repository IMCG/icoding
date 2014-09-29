//并差集入门
#include <iostream>
using namespace std;
#pragma warning(disable:4996)

const int MAX_N = 50001;
int par[MAX_N];
int N, K;
//init
void init(int n){
	for (int i = 1; i <= n; ++i){
		par[i] = i;
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
	par[x] = y;
}

int n, m;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	int num = 1, a, b;
	while (scanf("%d%d", &n, &m)==2){
		if (!n&&!m)
			break;
		//老是忘记初始化
		init(n);
		while (m--){
			scanf("%d%d", &a, &b);
			//if (!same(a, b))
				unite(a, b);
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i)
			if (par[i] == i)
				ans++;
		printf("Case %d: %d\n", num++, ans);
	}

#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif // !ONLINE_JUDGE
	return 0;
}


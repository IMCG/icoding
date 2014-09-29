//并差集
#include <iostream>
#pragma warning(disable:4996)
using namespace std;
#define MAX_N 1000

int par[MAX_N];
int high[MAX_N];	

void init(int n){
	//i初始值根据情况而定
	for (int i = 1; i <= n; ++i){
		par[i] = i;
		high[i] = 0;
	}
}
//find
int find(int x){
	return par[x] == x ? x : par[x] = find(par[x]);
}
//union
void unite(int x, int y){
	x = find(x);
	y = find(y);
	if (x == y)return;
	if (high[x] < high[y])
		par[x] = y;
	else{
		par[y] = x;
		if (high[x] == high[y])
			high[x]++;
	}
}
//isSame
bool same(int x, int y){
	return find(x) == find(y);
}
int main()
{
	int n, m, x, y;
	//freopen("E:\\in.txt", "r", stdin);
	while (scanf("%d", &n), n){
		init(n);
		for (scanf("%d", &m); m > 0; m--){
			scanf("%d %d", &x, &y);
			unite(x, y);
		}
		int count = -1;
		for (int i = 1; i <= n; ++i)
			if (par[i] == i)
				count++;
		printf("%d\n", count);
	}
	fclose(stdin);
	return 0;
}
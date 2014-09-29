//@任意两个房间有且仅有一条路径可以相通
//@没有环形
//http://www.tuicool.com/articles/U7ZbQj
#include <iostream>
#pragma warning(disable:4996)
using namespace std;
#define MAX_N 100005

int par[MAX_N];
int high[MAX_N];	
int visited[100005];

void init(int n){
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
//并差集判断是否有环
int main()
{
	freopen("E:\\in.txt", "r", stdin);
	int x, y;
	while (1){
		init(100005);
		memset(visited, 0, sizeof(visited));
		bool flag = 1;
		int k = 0;
		while (scanf("%d %d", &x, &y)==2){
			visited[x] = 1;
			visited[y] = 1;
			if (x == 0 && y == 0 || x == -1 && y == -1)
				break;
			same(x, y) ? (flag = 0) : unite(x, y);
		}
		if (x == -1 && y == -1)
			break;
		int sum = 0;
		for (int i = 1; i <= 100005; ++i){
			if (visited[i]&&par[i] == i)
				sum++;
			if (visited[i] != 0)
				k++;
		}
		if (k == 0)
			printf("Yes\n");
		else if (sum==1 && flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	fclose(stdin);
	return 0;
}

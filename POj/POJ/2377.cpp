//kruskal 最大生成树
//没考虑 不生成MST的情况
#include <iostream>
#include <algorithm>
using namespace std;

#pragma warning(disable:4996)
#define MAX_E 20000+16
#define MAX_V 1000+16
int parent[MAX_V];
int high[MAX_V];
void init(int n){
	for (int i = 0; i < n; ++i){
		parent[i] = i;
		high[i] = 0;
	}
}
int find(int x){
	return parent[x] == x ? x : parent[x] = find(parent[x]);
}
bool same(int x, int y){
	return find(x) == find(y);
}
void unite(int x, int y){
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	if (high[x] < high[y])
		parent[x] = y;
	else{
		parent[y] = x;
		if (high[x] == high[y])
			++high[x];
	}
}
//END
struct edge{
	int from, to, cost;
	edge(int _from=0,int _to=0,int _cost=0):
		from(_from), to(_to), cost(_cost){}
	bool operator < (const edge&b) const{
		return cost < b.cost;
	}
};
edge G[MAX_E];
int N, M;
int kruskal(int n){
	//加入MST的节点数
	int ans = 1;
	sort(G, G + n);
	init(N);
	int res = 0;
	for (int i = 0; i < n; ++i){
		edge e = G[i];
		if (!same(e.from, e.to)){
			res += e.cost;
			unite(e.from, e.to);
			ans++;
		}
	}
	return ans < N ? 1 : res;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt","r",stdin);
#endif // ONLINE_JUDGE

	cin >> N >> M;
	//三个变量也可以省去
	int a, b, c;
	for (int i = 0; i < M; ++i){
		cin >> a >> b >> c;
		G[i].from = a - 1;
		G[i].to = b - 1;
		G[i].cost = -c;
	}
	cout << -kruskal(M) << "\n";
}
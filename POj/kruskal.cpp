/*按照边的权值从小到大尝试加入最小树，如果不产生圈就加进去，否则就扔掉。

关于判断是否产生圈，可以利用并查集来高效地实现。连通的顶点放入一个并查集
（连通分量）里，如果一条边e的两个顶点u, v不在同一个连通分量中，那么将e加进来
也不会产生圈。
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_E 1024

// 并查集相关数据与算法
#define MAX_N MAX_E + 16
int parent[MAX_N];
int height[MAX_N];

void init(const int& n){
	for (int i = 0; i < n; ++i){
		parent[i] = i;
		height[i] = 0;
	}
}

int find(const int& x){
	return parent[x] == x ? x : parent[x] = find(parent[x]);	
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	if (height[x] < height[y]){
		parent[x] = y;
	}
	else
	{
		parent[y] = x;
		if (height[x] == height[y]){
			++height[x];
		}
	}
}

bool same(const int& x, const int& y){
	return find(x) == find(y);
}
//End of 并差集

struct edge{
	int u, v, cost;
	edge(int u = 0, int v = 0, int cost = 0) 
		: u(u), v(v), cost(cost) {}
	bool operator < (const edge & e2) const{
		return cost < e2.cost;
	}
};
edge es[MAX_E];
int V, E;
int kruskal()
{
	sort(es, es + E);//按照权排序
	init(V);
	int res = 0;
	for (int i = 0; i < E; ++i){
		edge e = es[i];
		if (!same(e.u, e.v)){
			unite(e.u, e.v);
			res += e.cost;
		}
	}
	return res;
}
int main(int argc, char *argv[])
{
	cin >> V >> E;
	for (int i = 0; i < E; ++i){
		cin >> es[i].u >> es[i].v >> es[i].cost;
	}
	cout << kruskal() << endl;
	return 0;
}
//最大生成树 总消耗减去M(ax)ST
//AOJ提交时候注意头文件以及宏的限制
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX_N 10000+5
#pragma warning(disable:4996)

//Begin
#define MAX_E MAX_N * MAX_N / 2 + 1
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
//End of 

struct edge{
	int u, v;
	double cost;
	edge(int u = 0, int v = 0, double cost = 0.0)
		: u(u), v(v), cost(cost) {}
	bool operator < (const edge & e2) const{
		return cost > e2.cost;
	}
};

edge es[MAX_E];
int V, E;
double kruskal()
{
	sort(es, es + E);//按照权排序
	init(V);
	double res = 0;
	for (int i = 0; i < E; ++i){
		edge e = es[i];
		if (!same(e.u, e.v)){
			unite(e.u, e.v);
			res += e.cost;
		}
	}
	return res;
}
typedef pair<int, int>ip;
ip dis[MAX_N];
int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE

	cin >> V >> E;
	for (int i = 0; i < V; ++i){
		cin >> dis[i].first >> dis[i].second;
	}
	double sum = 0.0;
	for (int i = 0; i < E; ++i){
		cin >> es[i].u >> es[i].v;
		--es[i].u; --es[i].v;
		int dx = dis[es[i].u].first - dis[es[i].v].first;
		int dy = dis[es[i].u].second - dis[es[i].v].second;
		es[i].cost = sqrt(dx * dx + dy * dy);
		sum += es[i].cost;
	}
	printf("%.3lf", sum - kruskal());
	return 0;
}
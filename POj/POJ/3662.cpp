//POJ 3662 Good
//@本身是一个图，就要想图算法。
//无向图
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#pragma warning(disable:4996)
using namespace std;
const int mx = 1024;
const int ml = 1000001;
struct edge{
	int to, cost;
	edge(){}
	edge(int to, int cost){
		this->to = to;
		this->cost = cost;
	}
};
//dist  no.
typedef pair<int, int>P;
vector<edge> G[mx];
int d[mx];
int V, E;
// 权小于x的边免费
// 返回需要的电线数量(即权大于x的边数)
// 改变权值cost>=x?1:0 结果为>=x边的个数 然后和K比较
int dijkstra(int s,int x){
	priority_queue<P, vector<P>, greater<P> >que;
	que.push(P(0, s));
	memset(d, 0x3f, sizeof(d));
	d[s] = 0;
	while (!que.empty()){
		P p = que.top(); que.pop();
		int v = p.second;
		if (d[v] < p.first)continue;
		for (int i = 0; i < (int)G[v].size(); ++i){
			edge e = G[v][i];
			int new_d = d[v] + (e.cost >= x ? 1 : 0);
			if (d[e.to]>new_d){
				d[e.to] = new_d;
				que.push(P(d[e.to], e.to));
			}
		}
	}
	return d[V - 1];
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	int K, from, to, cost;
	cin >> V >> E >> K;
	for (int i = 0; i < E; ++i){
		cin >> from >> to >> cost;
		--from;
		--to;
		G[from].push_back(edge(to, cost));
		G[to].push_back(edge(from, cost));
	}
	int lb = 0, ub = ml + 2;
	while (lb + 1 < ub){
		int mid = (lb + ub) >> 1;
		(dijkstra(0, mid) > K) ? lb = mid : ub = mid;
	}
	cout << (lb > ml ? -1 : lb) << "\n";
	return 0;
}
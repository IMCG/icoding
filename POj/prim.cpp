//prim
//MST Minimum Spanning Tree
/*从顶点出发，不断添加边
*/
#include <iostream>
#include <queue>
#include <functional>
#include <vector>
using namespace std;
#define MAX_V 1024
#define forn(i,n) for(int i=0;i<(int)n;++i)

int mincost[MAX_V];//从集合x出发的边到各顶点的最小权值
bool used[MAX_V];//顶点i是否包括在x集合中
int V;//顶点数

// first 最短路径，second顶点编号
typedef pair<int, int>P;
//边含有权重
struct edge{
	int to, cost;
	edge(int to = 0, int cost = 0) :cost(cost), to(to){}
};
// G[i] 顶点i到G[i].to的权值为G[i].cost
vector<edge> G[MAX_V];
//用堆
int prim(){
	int res = 0;
	memset(mincost, 0x3f, V*sizeof(int));
	memset(used, 0, sizeof(used));
	mincost[0] = 0;
	
	priority_queue<P, vector<P>, greater<P>>que;
	que.push(P(0, 0));
	while (!que.empty()){
		auto p = que.top(); que.pop();
		int v = p.second;
		if (used[v] || p.first > mincost[v])
			continue;
		used[v] = true;
		res += mincost[v];
		forn(i, G[v].size()){
			edge e = G[v][i];
			// mincost[e.to]>mincost[v]+e.cost?
			if (mincost[e.to] > e.cost){
				mincost[e.to] = e.cost;
				que.push(P(mincost[e.to], e.to));
			}
		}
	}
	return res;
}
//不用堆
#define INF 0x3F3F3F3F
int cost[MAX_V][MAX_V]; //权值
int mincost[MAX_V];//从集合x出发的边到每个顶点的最小权值
bool used[MAX_V]; //顶点是否在x集合中
int V;

int prim1(){
	for (int i = 0; i < V; ++i){
		mincost[i] = INF;
		used[i] = 0;
	}
	mincost[0] = 0;
	int res = 0;

	while (true){
		int v = -1;
		//从不在x的顶点中选取到x权值最小的点
		//可以把这个步骤转化为 priority_queue
		for (int u = 0; u < V; ++u)
			if (!used[u] && (v == -1 || mincost[u] < mincost[v]))
				v = u;
		if (v == -1)break;
		used[v] = true;	//加入x集合
		res += mincost[v];

		for (int u = 0; u < V; ++u){
			mincost[u] = min(mincost[u], cost[v][u]);
		}
	}
	return res;
}


int main(){
	V = 7;
	G[0].push_back(edge(1, 10));
	G[1].push_back(edge(0, 10));
	G[0].push_back(edge(2, 2));
	G[2].push_back(edge(0, 2));
	G[1].push_back(edge(3, 5));
	G[3].push_back(edge(1, 5));
	G[2].push_back(edge(3, 7));
	G[3].push_back(edge(2, 7));
	G[2].push_back(edge(4, 1));
	G[4].push_back(edge(2, 1));
	G[2].push_back(edge(5, 3));
	G[5].push_back(edge(2, 3));
	G[3].push_back(edge(5, 1));
	G[5].push_back(edge(3, 1));
	G[3].push_back(edge(6, 8));
	G[6].push_back(edge(3, 8));
	G[5].push_back(edge(6, 5));
	G[6].push_back(edge(5, 5));
	cout << prim() << endl;
	return 0;
}
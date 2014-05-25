//kruskal 输入时处理Running error
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#pragma warning(disable:4996)
#define forn(i,n) for(int i=0;i<(int)n;++i)
const int MAX_N = 100 + 5;
int map[MAX_N][MAX_N];
struct edge{
	int from, to, cost;
	edge(int from = 0, int to = 0, int cost = 0) 
		:from(from), to(to), cost(cost){}
	bool operator<(const edge&b)const{
		return cost < b.cost;
	}
};
edge G[MAX_N];
//Start
int parent[MAX_N];
int high[MAX_N];
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
			high[x]++;
	}
}
//End
int T;
int kruskal(int n){
	sort(G, G + n);
	init(T);
	int res = 0;
	for (int i = 0; i < n; ++i){
		edge e = G[i];
		if (!same(e.from, e.to)){
			unite(e.from, e.to);
			res += e.cost;
		}
	}
	return res;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE

	//可以省去map[][]存储数据
	while (cin >> T){
		forn(i, T)
			forn(j, T)
			cin >> map[i][j];
		int index = 0;
		forn(i, T)
			forn(j, T)
			if (i < j&&map[i][j]){
				G[index].from = i;
				G[index].to = j;
				G[index++].cost = map[i][j];
			}
		//cout << index;
		cout << kruskal(index) << "\n";
	}
}
//prim
#include <iostream>
#include <vector>
#include <functional>
#include <queue>
using namespace std;

#define MAX_V 102
#pragma warning(disable:4996)
int mincost[MAX_V];
bool used[MAX_V];
int V;
//最短路径 顶点编号
typedef pair<int, int>P;
struct edge{
	int to, cost;
	edge(int to = 0, int cost = 0) : cost(cost), to(to) {}
};
vector<edge> G[MAX_V];

int prim(){
	int res = 0;
	memset(mincost, 0x3f, sizeof(mincost));
	memset(used, 0, sizeof(used));
	mincost[0] = 0;
	priority_queue<P, vector<P>, greater<P> >que;
	que.push(P(0, 0));
	while (!que.empty()){
		P p = que.top(); que.pop();
		int v = p.second;
		if (used[v] || p.first > mincost[v])
			continue;
		used[v] = true;
		res += mincost[v];
		for (int i = 0; i < (int)G[v].size(); ++i){
			edge e = G[v][i];
			if (mincost[e.to]>e.cost){
				mincost[e.to] = e.cost;
				que.push(P(mincost[e.to], e.to));
			}
		}
	}
	return res;
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif
	while (cin >> V && V){
		int cost;
		for (int i = 0; i < V; ++i){
			G[i].clear();
			for (int j = 0; j < V; ++j){
				cin >> cost;
				G[i].push_back(edge(j, cost));
			}
		}
		cout << prim() << endl;
	}
	return 0;
}
//AOJ Road Construction 2249
//先保证最短路径,再保证最小花费
//update:5/30...
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <string.h> //for memset
using namespace std;
#pragma warning(disable:4996)
#define MAX_V 10005
#define MAX_E 20005

struct edge{
	int to, dist, cost;
	edge(int to=0,int dist=0,int cost=0):
		to(to), dist(dist), cost(cost){}
};
int d[MAX_V];
vector<edge>G[MAX_V];
//前驱结点 注意不要个prev迭代器混淆
//前驱是边?
/*别用点作为前驱.

*/
vector<edge>Prev[MAX_V];
//距离 节点
typedef pair<int, int>P;
int N, M;
void dijstra(){
	memset(d, 0x3f, sizeof(d));
	for (int i = 0; i < N; i++) Prev[i].clear();
	priority_queue<P, vector<P>, greater<P> >que;
	d[0] = 0;
	que.push(P(0, 0));
	while (!que.empty()){
		auto cur = que.top(); que.pop();
		int v = cur.second;
		if (d[v] < cur.first)continue;
		for (auto& k : G[v]){
			if (d[k.to]>d[v] + k.dist){
				d[k.to] = d[v] + k.dist;
				Prev[k.to].clear();
				Prev[k.to].push_back(k);
				que.push(P(d[k.to], k.to));
			}
			else if (d[k.to] == d[v] + k.dist)
				Prev[k.to].push_back(k);
		}
	}
}
int cost(int v){
	int min_cost = 0x3f3f3f3f;
	for (int i = 0; i < Prev[v].size(); ++i)
		min_cost = min(min_cost, Prev[v][i].cost);
	return min_cost;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt","r",stdin);
#endif // !ONLINE_JUDGE

	while (cin >> N >> M){
		//clear
		for (int i = 0; i < N; ++i)G[i].clear();
		for (int i = 0; i < N; ++i)Prev[i].clear();
		if (!N&&!M)
			return 0;
		int a, b, c, d;
		for (int i = 0; i < M; ++i){
			cin >> a >> b >> c >> d;
			--a; --b;
			//bid图
			G[a].push_back(edge(b, c, d));
			G[b].push_back(edge(a, c, d));
		}
		dijstra();
		int res = 0;
		for (int i = 1; i < N; ++i)
			res += cost(i);
		cout << res << "\n";
	}
	return 0;
}
//这样模拟。找寻满足优先距离最短，
//然后费用最低的那个最低费用
// error:下标要求数组或指针类型?
int res = 0;
for (int i = 1; i < N; ++i){
	int min_cost = 0x3f3f3f3f;
	for (int j = 0; j < (int)G[i].size(); ++i)
		if (d[G[i][j].to] + G[i][j].dist == d[i]
			&& min_cost < G[i][j].cost)
			min_cost = G[i][j].cost;
	res += min_cost;
}
//直接代码Good
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
struct NODE{
	int to, dist, cost;
	NODE(int a, int b, int c){
		to = a, dist = b, cost = c;
	}
};
//这个很重要 重载后，相当于小项堆
//pair<int,int>有默认的重载
bool operator < (const NODE &a, const NODE &b){
	return a.dist != b.dist ? a.dist > b.dist : a.cost > b.cost;
}
int main(){
	int n, m;
	while (cin >> n >> m && (n || m)){
		vector< vector<NODE> > g(n);
		bool done[10000] = { 0 };
		int ans = 0;
		rep(i, m){
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			a--, b--;
			g[a].push_back(NODE(b, c, d));
			g[b].push_back(NODE(a, c, d));
		}
		priority_queue <NODE> Q;
		Q.push(NODE(0, 0, 0));
		while (Q.size()){
			NODE q = Q.top(); Q.pop();
			if (done[q.to])continue;
			else done[q.to] = true, ans += q.cost;
			rep(i, g[q.to].size()) Q.push(NODE(g[q.to][i].to, q.dist + g[q.to][i].dist, g[q.to][i].cost));
		}
		cout << ans << endl;
	}
}
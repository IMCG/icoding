//路径矩阵转置在计算
//注意交换数组方法
#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#define forn(i,n) for(int i=0;i<n;++i)
#pragma warning(disable:4996)
using namespace std;

#define MAX_V 1000+5
#define MAX_E 100000+5
struct edge{
	int to, cost;
	edge(int _to = 0, int _cost = 0) :to(_to), cost(_cost){}
};
vector<edge>G[MAX_E];
vector<edge>rG[MAX_E];
// 可修改左值?
// vector<vector<edge> > G(MAX_E);
// vector<vector<edge> > rG(MAX_E);

//first 最短路 second 节点
typedef pair<int, int>p;
//到a最短路
int d[MAX_V];
int rd[MAX_V];
int N, M, X;
int a, b, c;
void dijstra(int a){
	memset(d, 0x3f, sizeof(d));
	priority_queue<p, vector<p>, greater<p>>que;
	d[a] = 0;
	que.push(p(0, a));
	while (!que.empty()){
		p cur = que.top(); que.pop();
		int c = cur.second;
		if (cur.first > d[c])
			continue;
		forn(i, G[c].size()){
			edge e = G[c][i];
			if (d[e.to] > d[c] + e.cost){
				d[e.to] = d[c] + e.cost;
				que.push(p(d[e.to], e.to));
			}
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE

	cin >> N >> M >> X;
	while (M--){
		cin >> a >> b >> c;
		--a;
		--b;
		G[a].push_back(edge(b, c));
		rG[b].push_back(edge(a, c));
	}
	//swap
	dijstra(--X);
	swap(G, rG);
	swap(d, rd);
	// G = rG;
	// memcpy(rd, d, sizeof(d));
	dijstra(X);
	forn(i, N)
		d[i] += rd[i];
	cout << *max_element(d, d + N);
}
/*也可以通过这样来实现任意两点最短路径。和dijstra一样
	int d[MAX_V][MAX_V];
	memset(d[s], 0x3f, MAX_V * sizeof(int));
	然后forn(i,N)dijstra(i);
*/

//@2
//floyd  TLE
//路径矩阵转置在计算
#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#define forn(i,n) for(int i=0;i<n;++i)
#pragma warning(disable:4996)
using namespace std;

#define MAX_V 1000+5

int d[MAX_V][MAX_V];
int N, M, X;
int a, b, c;
void init(){
	memset(d, 0x3f, sizeof(d));
	forn(i, N)
		d[i][i] = 0;
}
void floyd(){
	forn(k, N)
		forn(i, N)
		forn(j, N)
		d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	//初始化的位置
	init();
	cin >> N >> M >> X;
	while (M--){
		cin >> a >> b >> c;
		--a;
		--b;
		d[a][b] = c;
	}
	floyd();
	--X;
	int res = 0;
	forn(i, N)
		res = max(res, d[i][X] + d[X][i]);
	cout << res << "\n";
}
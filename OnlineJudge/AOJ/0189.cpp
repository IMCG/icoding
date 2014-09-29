//最短路径	Floyd Warshall
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)

#define MAX_V 11
int d[MAX_V][MAX_V];//权值
int V;//定点数
int x[MAX_V];//x[i]表示以i为起点时最短路径之和
#define forn(i,n) for(int i=0;i<(int)n;++i)

void floyd_warshall(){
	forn(k, V)
		forn(i, V)
		forn(j, V)
		d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}
int main(){
	//AOJ提交时别用 宏
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE

	int E;
	while (cin >> E, E){
		memset(d, 0x3f, MAX_V*MAX_V*sizeof(int));
		forn(i, MAX_V)
			d[i][i] = 0;
		V = 0;
		forn(i, E){
			int u, v, cost;
			cin >> u >> v >> cost;
			d[u][v] = cost;
			d[v][u] = cost;
			V = max(V, max(v, u) + 1);
		}
		floyd_warshall();
		memset(x, 0, V*sizeof(int));
		forn(i, V)
			forn(j, V)
			x[i] += d[i][j];
		int ans = min_element(x, x + V) - x;
		cout << ans << " " << x[ans] << "\n";
	}
	return 0;
}
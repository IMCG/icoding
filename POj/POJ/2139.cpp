//floyd 注意数据处理方式
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f
#pragma warning(disable:4996)
#define forn(i,n) for(int i=0;i<n;++i)
#define MAX_V 300+5

int d[MAX_V][MAX_V];
int V;
int x[MAX_V];

void floyd_warshall(){
	forn(k, V)
		forn(i, V)
		forn(j, V)
		d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
}
int M, a;
/*
默认距离	INF
自己和自己 	0
有连接边的	1
*/
int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE

	cin >> V >> M;
	//初始化
	memset(d, 0x3f, sizeof(d));
	forn(i, V)
		d[i][i] = 0;
	//数据处理
	while (M--){
		cin >> a;
		//--x[i]为了保持节点同步从0开始
		forn(i, a){
			cin >> x[i]; --x[i];
		}
		forn(i, a)
			for (int j = i + 1; j < a; j++)
				d[x[i]][x[j]] = d[x[j]][x[i]] = 1;
	}
	floyd_warshall();
	int ans = INF;
	forn(i, V){
		int sum = 0;
		forn(j, V)
			sum += d[i][j];
		ans = min(ans, sum);
	}
	cout << 100 * ans / (V - 1) << "\n";
}
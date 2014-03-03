//BFS   迷宫问题
#include <iostream>
#include <queue>
using namespace std;
#define MAX 100
const int INF = 100000000;
typedef pair<int, int>MyP;
//input
char maze[MAX][MAX];//迷宫
int N, M;
int sx, sy;
int gx, gy; //终点坐标
int d[MAX][MAX]; //到各个位置的最短距离的数组
//4个方向移动的向量
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

//求从(sx,xy)到(gx,gy)的最短距离。如无法到达，则是INF
int bfs()
{
	queue<MyP>que;
	//初始化无法到达
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			d[i][j] = INF;
		}
	}
	//起点加入que,距离设为0
	que.push(MyP(sx, sy));
	d[sx][sy] = 0;

	while (!que.empty()){
		MyP p = que.front();
		que.pop();
		//判断是否为终点
		if (p.first == gx && p.second == gy)break;
		//四个方向的循环
		for (int i = 0; i < 4; i++){
			int nx = p.first + dx[i], ny = p.second + dy[i];
			//判断是否可以移动，以及是否访问过
			if (0 <= nx &&nx < N && 0 <= ny &&ny < M
				&&maze[nx][ny] != '#'&& d[nx][ny] == INF){
				que.push(MyP(nx, ny));
				d[nx][ny] = d[p.first][p.second] + 1;
			}
		}
	}
	return d[gx][gy];
}
void solve()
{
	int res = bfs();
	cout << res;
}
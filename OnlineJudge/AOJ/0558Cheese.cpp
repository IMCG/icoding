//这个题目其实就是求按顺序遍历地图上12345……这几个点的最短路径
//每次从前一个点到下一个点多了一个距离d[][]
//AOJ 0558
#include <iostream>
#include <queue>
#include <fstream>
using namespace std;

int h, w, n;
char map[1024][1024];
//到当前工厂距离
int d[1024][1024];
int direction[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
int factory[16][2];
typedef pair<int, int>point;

int bfs(int sx, int sy, int gx, int gy){
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			d[i][j] = -1;
	queue<point>q;
	q.push(point(sx, sy));
	d[sx][sy] = 0;
	while (!q.empty()){
		point cur = q.front();
		q.pop();
		if (cur == point(gx, gy))
			break;
		for (int i = 0; i < 4; ++i){
			int nx = cur.first + direction[i][0];
			int ny = cur.second + direction[i][1];
			if (nx >= 0 && ny >= 0 && nx < h&&ny < w
				&&map[nx][ny]!='X'&&d[nx][ny]==-1){
				q.push(point(nx, ny));
				d[nx][ny] = d[cur.first][cur.second] + 1;
			}
		}
	}
	return d[gx][gy];
}
int main(){
	//ifstream in("E:\\in.txt");
	while (cin >> h >> w >> n){
		if (!h || !w || !n)
			return 0;
		for (int i = 0; i < h; ++i){
			for (int j = 0; j < w; ++j){
				cin >> map[i][j];
				if (map[i][j] == 'S'){
					factory[0][0] = i;
					factory[0][1] = j;
					map[i][j] = '.';
				}
				else if (isdigit(map[i][j])){
					int index = map[i][j] - '0';
					factory[index][0] = i;
					factory[index][1] = j;
				}
			}
		}
		int step = 0;
		for (int i = 0; i < n; ++i){
			step += bfs(factory[i][0], factory[i][1], 
				factory[i + 1][0], factory[i + 1][1]);
		}
		cout << step << "\n";
	}
	return 0;
}
//dfs + 奇偶剪枝优化。
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#define MAX 10
using namespace std;

char maps[MAX][MAX];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int flag, r, c, t, sx, sy, ex, ey;

void dfs(int x, int y, int step)
{
	int tmp = t - step - abs(ex - x) - abs(ey - y);
	if (tmp < 0 || tmp % 2)return;

	for (int i = 0; i < 4; ++i)
	{
		int tx, ty;
		tx = x + dx[i];
		ty = y + dy[i];
		//printf("%d %d",tx,ty);
		if (maps[tx][ty] == 'D'&&step == t - 1){
			flag = 1;
			return;
		}
		if (maps[tx][ty] == '.'&&tx >= 1 && tx <= r&&ty >= 1 && ty <= c){
			maps[tx][ty] = 'X';//mask
			dfs(tx, ty, step + 1);
			maps[tx][ty] = '.';//回溯取消
			//if (flag == 1)return;
		}
	}
}
int main()
{
	int i, j, step;
	while (scanf_s("%d%d%d", &r, &c, &t) && r&&c&&t)
	{
		//getchar();
		for (i = 1; i <= r; ++i){
			for (j = 1; j <= c; ++j){
				scanf_s("%c", &maps[i][j]);
				//为了奇偶剪枝
				if (maps[i][j] == 'S'){
					sx = i;
					sy = j;
				}
				if (maps[i][j] == 'D'){
					ex = i;
					ey = j;
				}
			}
			getchar();
		}
		flag = 0;
		step = 0;
		dfs(sx, sy, step);
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
//TLE 必须包含各种剪枝
#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#pragma warning(disable:4996)
using namespace std;
int direction[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
char map[10][10];
int n, m, t;
int sx, sy;
int gx, gy;
int flag;
void dfs(int x, int y, int time){
	/*if (map[x][y] == 'D'&&time == t){
	flag = 1;
	return;
	}*/
	//奇偶剪纸
	int temp = t - time - abs(gx - x) - abs(gy - y);
	if (temp < 0 || temp & 1)
		return;
	for (int i = 0; i < 4; ++i){
		int nx = x + direction[i][0];
		int ny = y + direction[i][1];
		//时间的判断
		if (map[nx][ny] == 'D'&&time == t - 1){
			flag = 1;
			return;
		}
		if (nx >= 1 && ny >= 1 && nx <= n&&ny <= m
			&&map[nx][ny] != 'X'){
			map[nx][ny] = 'X';
			//t-->time
			dfs(nx, ny, time + 1);
			map[nx][ny] = '.';
		}
	}
	return;
}
//坐标从1开始
int main()
{
	//ifstream in("E:\\in.txt");
	while (cin>>n>>m>>t,t+m+n){
		int wall = 0;
		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= m; ++j){
				cin >> map[i][j];
				if (map[i][j] == 'S'){sx = i; sy = j;}
				else if (map[i][j] == 'D'){gx = i; gy = j;}
				else if (map[i][j] == 'X')wall++;
			}
		}
		if (n*m-wall <= t){
			cout << "NO\n";
			continue;
		}
		flag = 0;
		map[sx][sy] = 'X';
		dfs(sx, sy, 0);
		puts(flag ? "YES" : "NO");
	}
	return 0;
}
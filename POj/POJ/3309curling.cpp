//深度优先 好题
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
int w, h;
int map[32][32];
int min_step;
int sx, sy;
int direction[4][2]{{-1, 0}, { 0, 1 }, { 1, 0 }, { 0, -1 }};

void dfs(int x, int y, int step){
	if (step > min_step || step >= 10)
		return;
	for (int i = 0; i < 4; ++i){
		int nx = x;
		int ny = y;
		while (nx >= 0 && ny >= 0 && nx < h&&ny < w
			&& (map[nx][ny] == 0 || map[nx][ny] == 2)){
			nx += direction[i][0];
			ny += direction[i][1];
		}
		if (nx >= 0 && ny >= 0 && nx < h&&ny < w
			&&map[nx][ny] == 3){
			if (step + 1 < min_step)
				min_step = step + 1;
		}
		else if (!(nx - direction[i][0] == x&&ny - direction[i][1] == y)
			&& nx >= 0 && ny >= 0 && nx < h&&ny < w&&map[nx][ny] == 1){
			map[nx][ny] = 0;
			dfs(nx - direction[i][0], ny - direction[i][1], step + 1);
			map[nx][ny] = 1;
		}
	}
}
int main(){

	//ifstream in("E:\\in.txt");
	//如果不判断h,w会一直输出
	while ((cin >> w >> h), (w&&h) != 0){
		for (int i = 0; i < h; ++i){
			for (int j = 0; j < w; ++j){
				cin >> map[i][j];
				if (map[i][j] == 2){
					sx = i; sy = j;
				}
			}
		}
		int step = 0;
		min_step = 100;
		dfs(sx, sy, step);
		printf("%d\n", min_step == 100 ? -1 : min_step);
	}
	return 0;
}
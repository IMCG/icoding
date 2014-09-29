//深度优先 
//以后都以x为第x行，y为第y列。
//坐标(x,y)  (nx,ny)搞对了
#include <iostream>
#include <fstream>
using namespace std;
#define MAX_W 20
#define MAX_H 20
char room[MAX_W][MAX_H];
int W, H;
const int direction[4][2] = {
	{ -1, 0 },
	{ 0, 1 },
	{ 1, 0 },
	{ 0, -1 },
};
int step = 0;
int sx, sy;

int dfs(int &x, int &y){
	room[x][y] = '#';
	++step;
	for (int i = 0; i < 4; i++){
		int nx = x + direction[i][0];
		int ny = y + direction[i][1];
		if (nx >= 0 && ny >= 0 && nx < H&&ny < W&&room[nx][ny] == '.')
			dfs(nx, ny);
	}
	return step;
}
int main()
{
	//ifstream input("E:\\in.txt");
	while (cin >> W >> H){
		step = 0;
		int x, y;
		for (x = 0; x < H; ++x){
			for (y = 0; y < W; ++y)
			{
				cin >> room[x][y];
				if (room[x][y] == '@')
				{
					sx = x;
					sy = y;
				}
			}
		}
		cout << dfs(sx, sy) << endl;
	}
}
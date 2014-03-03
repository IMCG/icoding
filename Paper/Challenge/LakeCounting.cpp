//Lake Counting (Poj 2386)
//从任意的W开始，不停的把邻接的部分用'.'代替。
#include <cstdio>
using namespace std;
#define MAX_N 100
#define MAX_M 100
//input
int N, M;
char field[MAX_N][MAX_M + 1];

//现在位置 x,y
void dfs(int x, int y)
{
	field[x][y] = '.';
	//循环遍历移动的8个方向
	for (int dx = -1; dx <= 1; dx++){
		for (int dy = -1; dy <= 1; dy++){
			int nx = dx + x, ny = dy + y;
			//判断是否在园子里，以及是否有积水
			if (0 <= nx && nx < N && 0 <= ny&&ny < M && field[nx][ny] == 'W')
				dfs(nx, ny);
		}
	}
	return;
}
void solve()
{
	int res = 0;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (field[i][j] == 'W'){
				dfs(i, j);
				res++;
			}
		}
	}
	printf("%d\n", res);
}
int main()
{
	
}
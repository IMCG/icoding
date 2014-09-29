//set记录。弄清dfs时候要记录什么，step or number
#include <set>
#include <iostream>
#pragma warning(disable:4996)
using namespace std;
int map[5][5];
int direction[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
//set用于除去重复
set<int>vis;
//遍历时记录信息
void dfs(int x,int y,int step,int number){
	if (step == 5){
		vis.insert(number);
		return;
	}
	for (int i = 0; i < 4; ++i){
		int nx = x + direction[i][0];
		int ny = y + direction[i][1];
		//nx写成了ny   尼玛
		if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5){
			//step++;
			dfs(nx, ny, step + 1, number * 10 + map[nx][ny]);
			//step--;
		}
	}
}
int main()
{
	freopen("E:\\in.txt", "r", stdin);
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			cin >> map[i][j];
	//
	for (int i = 0; i < 5; ++i){
		for (int j = 0; j < 5; ++j){
			dfs(i, j, 0, map[i][j]);
		}
	}
	cout << vis.size() << "\n";
	return 0;
}
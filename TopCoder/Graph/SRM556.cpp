//bfs 考虑最短路径
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_N 60
bool map[MAX_N][MAX_N];
#define forn(i,n) for(int i=0;i<n;++i)
//first 节点,second 距离(xor)
typedef pair<int, int>p;
int d[MAX_N];
int maxProfit(vector<int>cityValues, vector<string>roads)
{
	int n = roads.size();
	forn(i, n)
		forn(j, n)
		map[i][j] = roads[i][j] == 'N' ? 0 : 1;
	//
	int res = d[0] = cityValues[0];
	queue<p>que;
	que.push(p(0, res));
	while (!que.empty()){
		auto cur = que.front(); que.pop();
		forn(i, n)
			if (map[cur.first][i]&&(cur.second^cityValues[i])>d[i]){
				d[i] = cur.second^cityValues[i];
				que.push(p(i, d[i]));
		}
	}
	//
	forn(i, n)
		res = max(res, d[i]);
	return res;
}

int main()
{
	vector<int>a{ 0, 7, 11, 5, 2 };
	vector<string>b{ "NYNYY",
		"YNYNN",
		"NYNNN",
		"YNNNN",
		"YNNNN" };//14
	vector<int>a{ 0, 4, 8, 32, 512 };
	vector<string>b{ "NYYYY",
		"YNNNN",
		"YNNNN",
		"YNNNN",
		"YNNNN" };//556
	cout << maxProfit(a, b) << "\n";
}
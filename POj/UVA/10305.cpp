//一次dfs拓扑排序
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
//#include "algostuff.h"
using namespace std;
const int maxn = 101;
vector<int> v[maxn];
bool vis[maxn];
vector<int>vs;

void dfs(int i){
	vis[i] = true;
	for (auto& k : v[i])
		if (!vis[k])dfs(k);
	vs.push_back(i);
}

int main()
{
	//freopen("E:\\in.txt", "r", stdin);
	int n, m, i, a, b;
	while (scanf("%d%d", &n, &m), n)
	{
		for (i = 1; i <= n; ++i) v[i].clear();
		while (m--)
		{
			scanf("%d%d", &a, &b);
			v[a].push_back(b);
		}
		memset(vis, 0, sizeof(vis));
		
		for (i = 1; i <= n; ++i)
			if (!vis[i]) dfs(i);
		//out
		reverse(vs.begin(), vs.end());
		for (auto& i : vs)
			printf("%d ", i);
		printf("\n");
	}
	return 0;
}

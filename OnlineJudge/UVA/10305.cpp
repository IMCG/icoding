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
/*每次调用别忘初始化 vs,v,vis..*/
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
		vs.clear();

		for (i = 1; i <= n; ++i)
			if (!vis[i]) dfs(i);
		//out
		reverse(vs.begin(), vs.end());
		//输出有点问题
		for (auto& i : vs)
			printf("%d ", i);
		printf("\n");
	}
	return 0;
}

//AC
const int maxn = 101;
bool vis[maxn];
vector<int> G[maxn];
int vs[maxn];
int cnt;

void dfs(int v){
	vis[v] = true;
	for (auto& i : G[v])
		if (!vis[i])dfs(i);
	vs[cnt++] = v;
}
int main(){
	//freopen("E:\\in.txt","r",stdin);
	int m, n, a, b, i;
	while (scanf("%d%d",&n,&m),n){
		for (i = 1; i <= n; ++i)G[i].clear();
		while (m--){
			scanf("%d%d", &a, &b);
			G[a].push_back(b);
		}
		cnt = 0;
		memset(vis, 0, sizeof(vis));
		for (i = 1; i <= n; ++i)
			if (!vis[i]) dfs(i);
		for (i = n - 1; i; --i)
			printf("%d ", vs[i]);
		printf("%d\n", vs[0]);
	}
	return 0;
}


//AC拓扑排序 通过不断取入度为0的方法排序。
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
//#include "algostuff.h"
using namespace std;
const int maxn = 101;
vector<int> G[maxn];
vector<int>ans;
int degree[maxn];
//节点数
int n, m, a, b;
void topsort(){
	
	queue<int> que;
	for (int i = 1; i <= n; ++i){
		if (degree[i] == 0){ 
			que.push(i); 
		}
	}
	while (!que.empty()){
		auto t = que.front(); que.pop();
		ans.push_back(t);
		for (auto& k : G[t]){
			if (--degree[k] == 0)
				que.push(k);
		}
	}
}
int main(){
	//freopen("E:\\in.txt", "r", stdin);
	while ((cin >> n >> m),n){
		for (int i = 1; i <= n; ++i)G[i].clear();
		memset(degree, 0, sizeof(degree));
		while (m--){
			cin >> a >> b;
			G[a].push_back(b);
			degree[b]++;
		}
		ans.clear();
		topsort();
		for (int i = 0; i < n - 1; ++i)
			cout << ans[i] << " ";
		cout << ans[n - 1] << "\n";
	}
	return 0;
}
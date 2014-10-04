//当存在后向边时
//dfs如何考虑
// color array 
//白色(没访问) 灰色(访问过) 黑色(所有后继都访问过了)
//AC
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#define REPI(i, b, n) for (int i = b; i <= n; i++)
#define sii(a, b) scanf("%d%d", &a, &b)
#define read freopen("E:\\in.txt", "r", stdin)
#pragma warning(disable:4996)
using namespace std;
const int maxn = 1000003;
vector<int> G[maxn];
int vis[maxn];
int ans[maxn], cnt;

bool dfs(int v){
	vis[v] = 1;
	for (auto& k : G[v]){
		if (vis[k] == 1)return false;
		if (!vis[k] && !dfs(k))return false;
	}
	ans[cnt++] = v;
	vis[v] = 2;
	return true;
}
int main(){
	read;
	int n, m, a, b;
	bool ok;
	while (sii(n, m), n){
		REPI(i, 1, n)G[i].clear();
		while(m--)sii(a, b), G[a].push_back(b);
		memset(vis, 0, sizeof(vis));
		cnt = 0;
		ok = true;
		REPI(i, 1, n)if (!vis[i])ok &= dfs(i);
		if (ok)for (int i = n - 1; i >= 0; --i)printf("%d\n", ans[i]);
		else puts("IMPOSSIBLE");
	}
	return 0;
}




const int maxn = 1000003;

/*数组每次使用都要初始化*/
vector<int>G[maxn];
bool vis[maxn];
int ans[maxn], cnt;
int deg[maxn];
void dfs(int i){
	vis[i] = true;
	for (auto& k : G[i])
		if (!vis[k])dfs(k);
	ans[cnt++] = i;
}
//AC 注意数组初始化以及continue和break的使用
int main(){
	//read;
	int n, m, a, b, i;
	while (scanf("%d%d", &n, &m), n){
		for (i = 1; i <= n; ++i)G[i].clear();
		memset(deg,0,sizeof(deg));
		while (m--){
			scanf("%d%d", &a, &b);
			G[a].push_back(b);
			++deg[b];
		}
		int count = 0;
		for (i = 1; i <= n; ++i)
			if (deg[i] == 0)
				count++;

		if (count == 0){
			puts("IMPOSSIBLE");
			//不能用break;
			continue; 
		}
		memset(vis, 0, sizeof(vis));
		cnt = 0;
		for (i = 1; i <= n; ++i)
			if (!vis[i])dfs(i);
		for (i = n - 1; i >= 0; --i)
			printf("%d\n", ans[i]);
	}
	return 0;
}

//用bfs  入度为0的方法
//AC
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
//#pragma warning(disable:4996)
using namespace std;
#define fast ios_base::sync_with_stdio(false)
#define mem(a,v) memset(a,v,sizeof(a))
#define cpy(to, from) memcpy(to, from, sizeof(from))
#define ll long long 
#define sz(i) i.size()
#define all(a) a.begin(),a.end()
#define REP(i, b, n) for (int i = b; i < n; i++)
#define REPI(i, b, n) for (int i = b; i <= n; i++)
#define forn(i, n) REP(i, 0, n)
#define forni(i, n) REPI(i, 0, n)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define pi(a) printf("%d\n", a)
#define pii(a, b) printf("%d %d\n", a, b)
#define wh(t) while(t--)
#define read freopen("E:\\in.txt", "r", stdin)

const int maxn = 1000003;
vector<int>G[maxn];
int indeg[maxn];
int ans[maxn], cnt;

int n;
void bfs(){
	queue<int> que;
	REPI(i, 1, n)if (indeg[i] == 0)que.push(i);
	while (!que.empty()){
		int x = ans[cnt++] = que.front();
		que.pop();
		for (auto& k : G[x])
			if (--indeg[k] == 0)que.push(k);
	}
}
int main(){
	//read;
	int m, a, b;
	while (sii(n, m), n){
		REPI(i, 1, n)G[i].clear();
		mem(indeg, 0);
		wh(m){ 
		sii(a, b);
		G[a].push_back(b);
		indeg[b]++;}
		cnt = 0;
		bfs();
		if (cnt == n)forn(i, n)printf("%d\n", ans[i]);
		else puts("IMPOSSIBLE");
	}
	return 0;
}
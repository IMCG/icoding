//SCC kosaraju算法
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 100;

int n; // 顶点数  
vector<int> G[maxn]; // 图的邻接表表示  
vector<int> rG[maxn]; // 把边反向后的图  
vector<int> vs; // 后续遍历顺序的顶点列表  
bool used[maxn]; // 访问标记  
int cmp[maxn]; // 所属强连通分量的拓扑序  

void add_edge(int from, int to){
	G[from].push_back(to);
	rG[to].push_back(from);
}

void dfs(int x){
	used[x] = true;
	for (int i = 0; i < G[x].size(); i++){
		if (!used[G[x][i]]) dfs(G[x][i]);
	}
	vs.push_back(x);
}

void rdfs(int x, int k){
	used[x] = true;
	cmp[x] = k;
	for (int i = 0; i < rG[x].size(); i++){
		if (!used[rG[x][i]]) rdfs(rG[x][i], k);
	}
}

int scc(){
	memset(used, 0, sizeof(used));
	vs.clear();
	for (int i = 0; i < n; i++){
		if (!used[i]) dfs(i);
	}
	memset(used, 0, sizeof(used));
	int k = 0;
	for (int i = vs.size() - 1; i >= 0; i--){
		if (!used[vs[i]]) rdfs(vs[i], k++);
	}
	return k;
}
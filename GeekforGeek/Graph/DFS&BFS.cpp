//DFS & BFS
//注意定义连接表方式
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct edge{
	int v;
	edge(int _v) :v(_v){}
};
#define maxn 100
//节点数
int V;
//连接矩阵
vector<edge> G[maxn];
void DFSUtil(int v, bool visited[]){
	visited[v] = true;
	cout << v << " ";

	for (auto& t : G[v]){
		if (!visited[t.v])
			DFSUtil(t.v, visited);
	}
}
//遍历所有
void DFS(){
	bool *visited = new bool[V];
	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < V; ++i)
		if (!visited[i])
			DFSUtil(i, visited);
}
//遍历极大连通子图
void DFS(int v){
	bool *visited = new bool[V];
	memset(visited, 0, sizeof(visited));

	DFSUtil(v, visited);
}

void BFS(int v){
	bool *visited = new bool[V];
	memset(visited, 0, sizeof(visited));
	queue<int> qu;

	visited[v] = true;
	qu.push(v);

	while (!qu.empty()){
		v = qu.front();
		cout << v << " ";
		qu.pop();

		for (auto& i : G[v]){
			if (!visited[i.v]){
				visited[i.v] = true;
				qu.push(i.v);
			}
		}
	}
}
int main(){
	V = 4;
	G[0].push_back(edge(1));
	G[0].push_back(edge(2));
	G[1].push_back(edge(2));
	G[2].push_back(edge(0));
	G[2].push_back(edge(3));
	G[3].push_back(edge(3));
	//DFS();
	BFS(2);
	return 0;
}


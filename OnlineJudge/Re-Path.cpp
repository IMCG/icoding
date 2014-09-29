#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <iterator>
using namespace std;
 
#define MAX_V 1024
 
// 从顶点from指向顶点to的权值为cost的边
struct edge
{
    int to, cost;
    edge(){}
    edge(int to, int cost)
    {
        this->to = to;
        this->cost = cost;
    }
};
 
// first 最短路径，second顶点编号
typedef pair<int, int> P;
 
// 边
vector<edge> G[MAX_V];
 
// 最短距离
int d[MAX_V];
// V是顶点数，E是边数
int V, E;
 
int prev_vertex[MAX_V];    // 最短路上的前驱顶点
 
// 求解从顶点s出发到所有点的最短距离
void dijkstra(int s)
{
    priority_queue<P, vector<P>, greater<P> > que;
    memset(d, 0x3f, V * sizeof(int));
    d[s] = 0;
    que.push(P(0, s));
 
    while (!que.empty())
    {
        P p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); ++i)
        {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost)
            {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
                prev_vertex[e.to] = v;
            }
        }
    }
}
 
// 到顶点t的最短路
vector<int> get_path(int t)
{
    vector<int> path;
    for (; t != -1; t = prev_vertex[t])
    {
        path.push_back(t);
    }
    reverse(path.begin(), path.end());
    return path;
}
 
 
///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
    prev_vertex[0] = -1;
    // 测试数据
    V = 7;
    E = 20;
    G[0].push_back(edge(1, 2));
    G[1].push_back(edge(0, 2));
    G[0].push_back(edge(2, 5));
    G[2].push_back(edge(0, 5));
    G[1].push_back(edge(2, 4));
    G[2].push_back(edge(1, 4));
    G[1].push_back(edge(3, 6));
    G[3].push_back(edge(1, 6));
    G[1].push_back(edge(4, 10));
    G[4].push_back(edge(1, 10));
    G[2].push_back(edge(3, 2));
    G[3].push_back(edge(2, 2));
    G[3].push_back(edge(5, 1));
    G[5].push_back(edge(3, 1));
    G[4].push_back(edge(5, 3));
    G[5].push_back(edge(4, 3));
    G[4].push_back(edge(6, 5));
    G[6].push_back(edge(4, 5));
    G[5].push_back(edge(6, 9));
    G[6].push_back(edge(5, 9));
    // 测试数据结束
    dijkstra(0);
    cout << d[V - 1] << endl;
    auto path = get_path(V - 1);
    copy(path.begin(), path.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    system("pause");
    return 0;
}
//农夫能否通过洞回到过去，
//即判断是否有负环
#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

#define MAX_E (2500 + 200 + 16) * 2

// 从顶点from指向顶点to的权值为cost的边
struct edge{
    int from, to, cost;
    edge(){}
    edge(int from = 0, int to = 0, int cost = 0) :
        from(from), to(to), cost(cost){}
};
// 边
edge es[MAX_E];
// 最短距离
int d[MAX_E];
// V是顶点数，E是边数
int V, E;
// 是否存在负圈
bool find_negative_loop()
{
    memset(d, 0, sizeof(d));
    for (int i = 0; i < V; ++i){
        for (int j = 0; j < E; ++j){
            edge e = es[j];
            if (d[e.to] > d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
                // 如果更新了V次，则存在负圈
                if (i == V - 1){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("E:\\in.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--){
        int N, M, W;
        cin >> N >> M >> W;
        V = N;
        E = 0;
        int from, to, cost;
        for (int i = 0; i < M; ++i){
            cin >> from >> to >> cost;
            --from;
            --to;
            es[E].from = from;
            es[E].to = to;
            es[E].cost = cost;
            ++E;
            // 无向图再来一次
            es[E].from = to;
            es[E].to = from;
            es[E].cost = cost;
            ++E;
        }
        for (int i = 0; i < W; ++i){
            cin >> from >> to >> cost;
            --from;
            --to;
            es[E].from = from;
            es[E].to = to;
            es[E].cost = -cost;
            ++E;
        }
        puts(find_negative_loop() ? "YES" : "NO");
    }
    return 0;
}
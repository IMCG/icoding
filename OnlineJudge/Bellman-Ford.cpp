//单源最短路径
#include <iostream>
using namespace std;

#define MAX_E 1024

// 从顶点from指向顶点to的权值为cost的边
struct edge
{
	int from, to, cost;
	edge(){}
	edge(int from, int to, int cost)
	{
		this->from = from;
		this->to = to;
		this->cost = cost;
	}
};

// 边
edge es[MAX_E];

// 最短距离
int d[MAX_E];
// V是顶点数，E是边数
int V, E;

// 求解从顶点s出发到所有点的最短距离
void shortest_path(int s)
{
	memset(d, 0x3f, V * sizeof(int));
	d[s] = 0;
	while (true)
	{
		bool update = false;
		for (int i = 0; i < E; ++i)
		{
			edge e = es[i];
			if (d[e.from] != 0x3f3f3f3f && d[e.to] > d[e.from] + e.cost)
			{
				d[e.to] = d[e.from] + e.cost;
				update = true;
			}
		}
		if (!update)
		{
			break;
		}
	}
}

// 是否存在负圈
bool find_negative_loop()
{
	memset(d, 0, sizeof(d));
	for (int i = 0; i < V; ++i)
	{
		for (int j = 0; j < E; ++j)
		{
			edge e = es[j];
			if (d[e.to] > d[e.from] + e.cost)
			{
				d[e.to] = d[e.from] + e.cost;
				// 如果更新了V次，则存在负圈
				if (i == V - 1)
				{
					return true;
				}
			}
		}
	}
	return false;
}

///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
	// 测试数据
	V = 7;
	E = 20;
	es[0] = edge(0, 1, 2);
	es[1] = edge(0, 2, 5);
	es[2] = edge(1, 2, 4);
	es[3] = edge(1, 3, 6);
	es[4] = edge(1, 4, 10);
	es[5] = edge(2, 3, 2);
	es[6] = edge(3, 5, 1);
	es[7] = edge(4, 5, 3);
	es[8] = edge(4, 6, 5);
	es[9] = edge(5, 6, 9);
	// 无向图必须重复一遍
	es[10] = edge(1, 0, 2);
	es[11] = edge(2, 0, 5);
	es[12] = edge(2, 1, 4);
	es[13] = edge(3, 1, 6);
	es[14] = edge(4, 1, 10);
	es[15] = edge(3, 2, 2);
	es[16] = edge(5, 3, 1);
	es[17] = edge(5, 4, 3);
	es[18] = edge(6, 4, 5);
	es[19] = edge(6, 5, 9);
	// 测试数据结束
	cout << "negative loop ? " << boolalpha << find_negative_loop() << endl;
	shortest_path(0);
	cout << d[V - 1] << endl;
	system("pause");
	return 0;
}
//递推公式
//d[i] = min{d[j] + cost[i to j]}。
#define MAX_V 1024

// 从顶点from指向顶点to的权值为cost的边
struct edge{
	int to, cost;
	edge(){}
	edge(int to, int cost){
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

// 求解从顶点s出发到所有点的最短距离
// 不用used[]
void dijkstra(int s)
{
	priority_queue<P, vector<P>, greater<P> > que;
	memset(d, 0x3f, V * sizeof(int));
	d[s] = 0;
	que.push(P(0, s));

	while (!que.empty()){
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
			}
		}
	}
}

//1
int cost[maxn][maxn];
int d[maxn];
bool used[maxn];
int V;

void dijkstra(int s){
	fill(d,d+V,INF);
	fill(used,used+V,false);
	d[s]=0;

	while(true){
		int v=-1;
		// 从尚未使用过的顶点中选择一个距离最小的
		for(int u=0;u<V;++u)
			if(!used[u]&&(v==-1||d[u]<d[v]))
				v=u;

		if(v==-1)break;
		used[v]=true;

		for(int u=0;u<V;++u){
			d[u]=min(d[u],d[v]+cost[v][u]);
		}
	}
}
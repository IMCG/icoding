//C++
#include <iostream>
#include <list>
using namespace std;
class Graph{
	int V;
	list<int> *adj;
public:
	Graph(int V);
	void addEdge(int v, int w);
	void print();
};
Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}
void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}
void Graph::print(){
	for (int v = 0; v < V; ++v){
		cout << v << "--";
		for (auto& b : adj[v])
		{
			cout << b << " ";
		}
		cout << endl;
	}
}
int main()
{
	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(0, 4);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.print();

	return 0;
}
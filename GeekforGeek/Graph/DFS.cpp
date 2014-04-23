//Depth First Traversal for a Graph
#include <iostream>
#include <list>
using namespace std;

// Graph class represents a directed graph using adjacency list representation
class Graph
{
	int V;    // No. of vertices
	list<int> *adj;    // Pointer to an array containing adjacency lists
	void DFSUtil(int v, bool visited[]);  // A function used by DFS
public:
	Graph(int V);   // Constructor
	void addEdge(int v, int w);   // function to add an edge to graph
	void DFS(int v);    // DFS traversal of the vertices reachable from v
	void DFS();			// prints DFS traversal of the complete graph
	/*void DFS(int v=0); 一个默认参数
	*/
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}
void Graph::DFSUtil(int v, bool visited[]){
	// Mark the current node as visited and print it
	visited[v] = true;
	cout << v << " ";

	// Recur for all the vertices adjacent to this vertex
	for (auto i = adj[v].begin(); i != adj[v].end(); ++i){
		if (!visited[*i])
			DFSUtil(*i, visited);
	}
}
void Graph::DFS(int v){
	// Mark all the vertices as not visited
	bool *visited = new bool[V];
	fill(visited, visited+V, false);
	// Call the recursive helper function to print DFS traversal
	DFSUtil(v, visited);
}
// The function to do DFS traversal. It uses recursive DFSUtil()
void Graph::DFS()
{
	// Mark all the vertices as not visited
	bool *visited = new bool[V];
	//fill(visited, visited+V, false);
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Call the recursive helper function to print DFS traversal
	// starting from all vertices one by one
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			DFSUtil(i, visited);
}

int main()
{
	// Create a graph given in the above diagram
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Depth First Traversal (starting from vertex 2) \n";
	g.DFS();

	return 0;

}
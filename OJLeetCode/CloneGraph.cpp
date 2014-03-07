/*Clone an undirected graph. Each node in the graph contains a label 
and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node 
label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three 
parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), 
thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/
//Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == nullptr)return nullptr;
		//key is original node,value is copied node
		unordered_map<const UndirectedGraphNode *, 
			UndirectedGraphNode*>copied;
		clone(node, copied);
		return copied[node];
	}
private:
	//DFS
	static UndirectedGraphNode* clone(const UndirectedGraphNode *node,
		unordered_map<const UndirectedGraphNode*,
		UndirectedGraphNode *>&copied){
		//a copy already exists 收敛条件
		if (copied.find(node) != copied.end())
			return copied[node];
		UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
		copied[node] = new_node;
		for (auto& nbr : node->neighbors){
			new_node->neighbors.push_back(clone(nbr, copied));
		}
		return new_node;
	}
};
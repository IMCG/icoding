#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct node{
	int val;
	node*left;
	node*right;
	node(int x) :val(x), left(nullptr), right(nullptr){}
};
node*newNode(int elem)
{
	node*cur = new node(elem);
	cur->left=NULL;
	cur->right=NULL;
	return cur;
}
node*InsertNode(node*root, int elem)
{
	if (root == nullptr)return newNode(elem);
	else if (elem <= root->val)
		root->left = InsertNode(root->left, elem);
	else
		root->right = InsertNode(root->right, elem);
	return root;
}
class Solution{
public:
	void travel(node*root, size_t level, vector<vector<int> > &result)
	{//add a bool true then !true
		if (!root)return;
		if (level > result.size())
			result.push_back(vector<int>());
		result[level - 1].push_back(root->val);

		travel(root->left, level + 1, result);
		travel(root->right, level + 1, result);
		/*How to use bool??
		if(left_to_right) Zigzag
			result[level - 1].push_back(root->val);
		else
			result[level - 1].insert(result[level-1],root->val);
		*/
	}
	vector<vector<int> >levelorder(node*root)
	{
		vector<vector<int> > result;
		travel(root, 1, result);
		return result;
	}
};
class Solution{
public:
		vector<vector<int> >levelorder(node*root)
	{
		vector<vector<int> >result;
		if (root == nullptr)return result;
		queue<node*>current, next;
		vector<int> level;//elements in level 

		current.push(root);
		while (!current.empty())
		{
			while (!current.empty())
			{
				node*cur = current.front();
				current.pop();
				level.push_back(cur->val);
				if (cur->left != nullptr)
					next.push(cur->left);
				if (cur->right != nullptr)
					next.push(cur->right);
			}
			result.push_back(level);
			level.clear();
			swap(next, current);
		}
		return result;
	}
};
};
void Print(vector<vector<int> > result)
{
	for (size_t i = 0; i < result.size(); i++)
	{
		for (size_t j = 0; j < result[i].size(); j++)
			cout << "[" << result[i][j] << "]";
		cout << endl;
	}
	cout << endl;
}
int main()
{
	int A[] = {5,3,8,1,4,7,9,6,10};
	node*root = nullptr;
	vector<vector<int> >result;
	for (int i = 0; i < 9; i++)
		root = InsertNode(root, A[i]);
	Solution s;
	result=s.levelorder(root);
	//reverse(result.begin(),end());
	Print(result);
}
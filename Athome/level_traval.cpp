//层次遍历
#include <iostream>  
#include <list>  
using namespace std;

// 树节点，包括左二子、右儿子指针和保存的值  
class TreeNode
{
public:
	TreeNode* _left;
	TreeNode* _right;
	int _val;

	TreeNode(int val, TreeNode* left = NULL, TreeNode* right = NULL) :
		_val(val), _left(left), _right(right){}
};

// 二叉树类  
class BSTree
{
public:
	TreeNode* _root;

	BSTree(TreeNode* root = NULL) : _root(root) {}

	// 往树里增加元素  
	void add(int val)
	{
		add(_root, val);
	}

	// 广度优先搜索  
	void BFS()
	{
		list<TreeNode*> s;
		if (_root == NULL) return;
		cout << "BFS squence:";

		// 将根节点放入链表，开始遍历  
		s.push_back(_root);

		while (s.size())
		{
			// 访问链表中的头节点  
			TreeNode* node = *s.begin();
			cout << node->_val << " ";
			s.pop_front();

			// 再将它的非空的左右儿子放入链表尾部  
			if (node->_left) s.push_back(node->_left);
			if (node->_right) s.push_back(node->_right);
		}
		cout << endl;
	}

private:


	// 使用递归比较简单  
	void add(TreeNode*& root, int val)
	{
		// 如果比根节点大，则添加到右子树，否则添加到左子树  
		if (root == NULL) root = new TreeNode(val);
		else
		{
			if (root->_val > val) add(root->_left, val);
			else add(root->_right, val);
		}
	}
};

// 测试主函数  
int main()
{
	// 建立搜索树  
	BSTree tree;
	tree.add(10);
	tree.add(8);
	tree.add(123);
	tree.add(11);
	tree.add(900);


	tree.BFS();
	system("pause");
	
}
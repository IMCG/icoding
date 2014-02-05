//尹成blog。0304镜像二叉树
/*输入一颗二叉查找树，将该树转换为它的镜像*/
#include<iostream>
using namespace std;
//树节点
class TreeNode{
public:
	int _val;
	TreeNode*_left;
	TreeNode*_right;
	TreeNode(int val) :_val(val), _left(nullptr), _right(nullptr){}
};

//二叉树类
class BSTree{
public:
	TreeNode*_root;

	BSTree(TreeNode*root = nullptr) :_root(root){}
	//add element
	void add(int val)
	{
		add(_root, val);
	}
	//midOrder
	void midOrder()
	{
		cout << "中序遍历： ";
		midOrder(_root);
		cout << endl;
	}
	//镜像
	void mirror()
	{
		mirror(_root);
	}
private:
	//镜像，使用递归:交换左右儿子
	void mirror(TreeNode*root)
	{
		if (root == nullptr)return;

		TreeNode*temp = root->_left;
		root->_left = root->_right;
		root->_right = temp;

		mirror(root->_left);
		mirror(root->_right);
	}
	//中序遍历，递归
	void midOrder(TreeNode*root)
	{
		if (root == nullptr)return;
		midOrder(root->_left);
		cout << root->_val << " ";
		midOrder(root->_right);
	}

	//使用递归比较简单
	void add(TreeNode*&root, int val)
	{
		if (root == nullptr) root = new TreeNode(val);
		else
		{
			if (root->_val < val)
				add(root->_left, val);
			else
				add(root->_right, val);
		}
	}
};

//测试主函数
int main()
{
	//建立二叉树
	BSTree tree;
	tree.add(10);
	tree.add(8);
	tree.add(123);
	tree.add(11);
	tree.add(900);

	//output
	tree.midOrder();

	//镜像输出
	tree.mirror();
	tree.midOrder();

	system("pause");
}
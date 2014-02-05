/*路径查找：在一棵树中，获取和为某个值的所有路径*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct node{
	int val;
	node*left;
	node*right;
	node(int n) :val(n), left(nullptr), right(nullptr){}
};
node*newNode(int elem)
{
	node*temp = new node(elem);
	temp->left = nullptr;
	temp->right = nullptr;
	return temp;
}
node*Insert(node*head, int elem)
{
	if (head == nullptr)return newNode(elem);
	else if (elem < head->val)
		head->left = Insert(head->left, elem);
	else
		head->right = Insert(head->right, elem);
	return head;
}
void FindSum(node*head, int sum, stack<node*>s)
{
	if (head == nullptr)return;

	s.push(head);
	//空树
	if (head->left == nullptr && head->right == nullptr)
	{
		if (sum == head->val)
		{
			while (!s.empty())
			{
				node*temp = s.top();
				s.pop();
				cout << temp->val << " ";
			}
		}
		cout << endl;
	}
	//非空。递归
	if (head->left != nullptr)
		FindSum(head->left, sum - head->val, s);
	if (head->right != nullptr)
		FindSum(head->right, sum - head->val, s);
}

//create
node*Creat()
{
	int val;
	node*head;
	cin >> val;
	//0 代表空节点
	if (val == 0)
		head == nullptr;
	else
	{
		head = new node(val);

		cout << "左子节点";
		head->left = Creat();
		cout << "右子节点";
		head->right = Creat();
	}
	return head;
}



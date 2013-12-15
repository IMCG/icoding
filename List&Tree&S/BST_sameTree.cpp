int hash_node[100];
void hash_tree(node*head)
{
	if (head == NULL)return;
	hash_node[head->data]++;
	hash_tree(head->left);
	hash_tree(head->right);
}
void dehash_tree(node*head)
{
	if (head == NULL)return;
	--hash_node[head->data];
	dehash_tree(head->left);
	dehash_tree(head->right);
}
bool sameTree1(node*a, node*b)
{
	if (a == NULL || b == NULL)return false;
	hash_tree(a);
	dehash_tree(b);

	for (int i = 0; i < 100; i++)
	{
		if (hash_node[i] == 0)
			return false;
	}
	return true;
}
//
#include<iostream>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 TreeNode*newNode(int elem)
 {
	 TreeNode*cur = new TreeNode(elem);
	 cur->left=NULL;
	 cur->right=NULL;
	 return cur;
 }
 TreeNode*insert_node(TreeNode*head, int elem)
 {
	 if (head == NULL)return newNode(elem);
	 else if (elem <= head->val)
		 head->left = insert_node(head->left, elem);
	 else
		 head->right = insert_node(head->right, elem);
	 return head;
 }
 void PrintTree(TreeNode*head)
 {
	 if (head == NULL)return;
	 PrintTree(head->left);
	 cout << head->val;
	 PrintTree(head->right);
	 cout << endl;
 }
class Solution {
public:
	bool isSameTree(TreeNode *p, TreeNode *q) {
		if (p == NULL && q == NULL) return true;
		else if (p == NULL || q == NULL)
			return false;
		else
			return p->val == q->val &&isSameTree(p->left, q->left) && isSameTree(p->right, p->right);
	}
};
class Solution1 {
public:
	bool isSameTree(TreeNode *p, TreeNode *q) {
		stack<TreeNode*>s;
		s.push(p);
		s.push(q);

		while (!s.empty())
		{
			p = s.top(); s.pop();
			q = s.top(); s.pop();

			if (!p&&!q)continue;
			if (!p || !q)return false;
			if (p->val != q->val)return false;

			s.push(p->right);
			s.push(q->right);
		}
		return true;
	}
};
int main()
{
	int A[] = { 12, -60 };
	int B[] = {12,72};
	TreeNode*a = NULL;
	TreeNode*b = NULL;
	for (int i = 0; i < 2; i++)
	{
		a = insert_node(a, A[i]);
		b = insert_node(b, B[i]);
	}
	cout << "a.......\n";
	PrintTree(a);
	cout << "b.......\n";
	PrintTree(b);
	Solution s;
	if (s.isSameTree(a, b))
		cout << "ok";
	else
		cout << "wrong";
}

/*Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which 
the depth of the two subtrees of every node never differ by more than 1.
(注意平衡树的定义。)
*/
#include <algorithm>
#include <iostream>
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
	cur->left = nullptr;
	cur->right = nullptr;
	return cur;
}
TreeNode*InsertNode(TreeNode*head, int elem)
{
	if (head == nullptr)return newNode(elem);
	else if (elem < head->val)
		head->left = InsertNode(head->left, elem);
	else
		head->right = InsertNode(head->right, elem);
	return head;
}
//TimeOut
class Solution {
public:
	bool isBalanced(TreeNode *root) {
		if (root == nullptr)return true;
		return abs((maxdep(root->left) - mindep(root->right)) <= 1) &&
			abs((maxdep(root->right) - mindep(root->left)) <= 1) &&
			isBalanced(root->left) && isBalanced(root->right);
	}
	int maxdep(TreeNode *root)
	{
		if (root == nullptr)
			return 0;
		else
			return max(maxdep(root->left), maxdep(root->right)) + 1;
	}
	int mindep(TreeNode *root)
	{
		if (root == nullptr)
			return 0;
		int left = mindep(root->left);
		int right = mindep(root->right);
		if (!(root->left))
			return right + 1;
		else if (!(root->right))
			return left + 1;
		else
			return min(left, right) + 1;
	}
};
class Solution {
public:
	bool isBalanced(TreeNode*root){
		return balancedHeight(root) >= 0;
	}
	/*
	 *Returns the height of 'root' if 'root' is a balanced tree
	 *otherwise,returns '1'
	 */
	int balancedHeight(TreeNode*root){
		if (root == nullptr)
			return 0;		//终止
		int left = balancedHeight(root->left);
		int right = balancedHeight(root->right);
		if (left < 0 || right<0 || abs(left - right)>1)
			return -1;//剪枝
		return max(left, right) + 1;//三方合并
	}
};
int main()
{
	const int N = 6;
	int A[N] = { 5, 3, 8, 7, 9, 6};
	TreeNode*head = nullptr;
	for (int i = 0; i < N; i++)
	head = InsertNode(head, A[i]);
	Solution s;
	cout << s.maxdep(head) << endl;
	cout << s.mindep(head) << endl;
	cout << boolalpha << s.isBalanced(head);
	cout << endl;
}
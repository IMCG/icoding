/*Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //AC
class Solution {
public:
	bool isValidBST(TreeNode *root) {
		if (root == nullptr)return true;
		if (root->left && root->val <= Max(root->left))
			return false;
		if (root->right && root->val >= Min(root->right))
			return false;
		if (!isValidBST(root->left) || !isValidBST(root->right))
			return false;
		return true;
	}
private:
	int Min(TreeNode *root){
		if(root==nullptr)return INT_MIN;
		while (root->left)
			root = root->left;
		return root->val;
	}
	int Max(TreeNode *root){
		if(root==nullptr)return INT_MAX;
		while (root->right)
			root = root->right;
		return root->val;
	}
};
//效率的版本。
bool isValidBST(TreeNode *root){
	return isBSTUtil(root,INT_MIN,INT_MAX);
}
int isBSTUtil(TreeNode *root,int min,int max)
{
	if(root==nullptr) return true;
	if(root->val <= min || root->val >= max)
		return false;
	return isBSTUtil(root->left,min,root->val) &&
		   isBSTUtil(root->right,root->val,max);
}
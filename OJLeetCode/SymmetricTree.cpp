/*Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
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
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
		if (root == nullptr)
			return true;
		else
			return isSymmetric(root->left, root->right);
	}
	bool isSymmetric(TreeNode*left, TreeNode*right)
	{
		if (!left && !right)
			return true;
		else if (!left || !right)
			return false;
		else
			return 	left->val==right->val 
			&& isSymmetric(left->left, right->right) 
			&& isSymmetric(left->right, right->left);
	}
};	

void mirror(TreeNode*root)
{
	if (root == nullptr)
		return;
	TreeNode*temp;
	mirror(root->left);
	mirror(root->right);

	temp = root->left;
	root->left = root->right;
	root->right = temp;
}
/*Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. 
Could you devise a constant space solution?
*/
class Solution {
public:
	void recoverTree(TreeNode *root) {
		vector<TreeNode *> inorder;
		inorderTraversal(root, inorder);
		TreeNode *first = nullptr, *second = nullptr;
		for (int i = 1; i < inorder.size(); ++i)
		{
			if (inorder[i - 1]->val < inorder[i]->val)
				continue;
			if (!first)
				first = inorder[i - 1];
			second = inorder[i];
		}
		swap(first->val, second->val);
	}
private:
	void inorderTraversal(TreeNode *root, vector<TreeNode *> &inorder) {
		if (!root) return;
		inorderTraversal(root->left, inorder);
		inorder.push_back(root);
		inorderTraversal(root->right, inorder);
	}
};
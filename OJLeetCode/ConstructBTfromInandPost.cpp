//Given inorder and postorder traversal of a tree, construct the binary tree.
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
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		return build(inorder.begin(), inorder.end(),
			postorder.begin(), postorder.end());
	}
	template <typename BidiIt>
	TreeNode *build(BidiIt in_first, BidiIt in_last,
		BidiIt post_first, BidiIt post_last)
	{
		if (in_first == in_last || post_first == post_last)return nullptr;
		TreeNode* root = new TreeNode(*(prev(post_last)));

		auto isRootPos = find(in_first, in_last, *(prev(post_last)));
		auto mysize = distance(in_first, isRootPos);
		root->left = build(in_first, isRootPos, post_first,
			next(post_first, mysize));
		root->right = build(next(isRootPos), in_last, next(post_first, mysize),
			prev(post_last));
		return root;
	}
};
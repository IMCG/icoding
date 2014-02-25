//Given preorder and inorder traversal of a tree, construct the binary tree.
//思路对，关于最后距离。
class Solution {
public:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		int m = preorder.size() - 1;
		int n = inorder.size() - 1;
		return buildSub(preorder, 0, m, inorder, 0, n);
	}
private:
	TreeNode*buildSub(vector<int>preorder, int pleft, int pright,
		vector<int>inorder, int ileft, int iright)
	{
		if (pleft > pright)return nullptr;
		if (ileft > iright)return nullptr;
		TreeNode*head = new TreeNode(preorder[pleft]);
		int i = ileft;
		while (i <= iright && inorder[i] != preorder[pleft])
			i++;
		//这里非得要算出来距离。
		head->left = buildSub(preorder, pleft + 1, pleft + i - ileft, inorder, ileft, i - 1);
		head->right = buildSub(preorder, pleft + i - ileft + 1, pright, inorder, i + 1, iright);
		return head;
	}
};
//泛型编程
class Solution {
public:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		return buildTree(preorder.begin(), preorder.end(),
			inorder.begin(), inorder.end());
	}
private:
	template<typename InputIterator>
	TreeNode*buildTree(InputIterator pre_first, InputIterator pre_last,
		InputIterator in_first, InputIterator in_last)
	{
		if (pre_first == pre_last)return nullptr;
		if (in_first == in_last)return nullptr;
		auto root = new TreeNode(*pre_first);

		auto inRootPos = find(in_first, in_last, *pre_first);
		auto leftSize = distance(in_first, inRootPos);
		root->left = buildTree(next(pre_first), next(pre_first,leftSize+1), 
			in_first, next(in_first,leftSize));
		root->right = buildTree(next(pre_first,leftSize+1), pre_last,
			next(inRootPos), in_last);
		return root;
	}

};
/*Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
*/
//不会，没考虑到可以从任意点出发
class Solution {
public:
	int maxPathSum(TreeNode *root) {
		if (root == nullptr)return 0;
		if (!(root->left) && !(root->right))
			return root->val;
		return maxSinglePath(root, 0);
	}
private:
	int maxSinglePath(TreeNode *root,int sum){
		if (!(root->left) && !(root->right))
			return max(sum, sum + root->val);

		if (root->left && root->right){
			int left = maxSinglePath(root->left, sum + root->val);
			left = max(left, sum + root->val);
			int right = maxSinglePath(root->right, sum + root->val);
			right = max(right, sum + root->val);
			return left + right - root->val;
		}
		else if(root->left){
			int left = maxSinglePath(root->left, sum + root->val);
			return left = max(left, sum + root->val);
		}
		else{
			int right = maxSinglePath(root->right, sum + root->val);
			return right = max(right, sum + root->val);
		}	
	}
};
//利用“最大连续子序列和”问题的思路，见第§13.2节。如果说Array 只有一个
//方向的话,那么Binary Tree 其实只是左、右两个方向而已，

class Solution{
public:
	int maxPathSum(TreeNode *root){
		max_sum = INT_MIN;
		dfs(root);
		return max_sum;
	}
private:
	int max_sum;
	int dfs(const TreeNode *root){
		if(root == nullptr)return 0;
		int l = dfs(root->left);
		int r = dfs(root->right);
		int sum = root->val;
		if(l > 0)sum += l;
		if(r > 0)sum += r;
		max_sum=max(max_sum,sum);
		//必须返回值，l,r从这里获得值
		return max(r,l)>0?max(r,l)+root->val:root->val;
	}
};

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int res = INT_MIN;
        maxPathSumRe(root, res);
        return res;
    }

    int maxPathSumRe(TreeNode *node, int &res)
    {
        if (!node) return 0;
        int l = maxPathSumRe(node->left, res);
        int r = maxPathSumRe(node->right, res);
        int sum = max(node->val, max(l, r) + node->val);
        res = max(res, sum);
        res = max(res, l + r + node->val);
        return sum;
    }
};

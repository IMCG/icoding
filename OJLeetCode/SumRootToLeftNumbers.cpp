/*Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example, 
    1
   / \
  2   3



The root-to-leaf path 1->2 represents the number 12.
 The root-to-leaf path 1->3 represents the number 13. 

Return the sum = 12 + 13 = 25. 

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
    int sumNumbers(TreeNode *root) {
        vector<int>result;
		if (root == nullptr)
			return 0;
		int cur = 0;
		help(root, result, cur);
		return accumulate(result.begin(), result.end(), 0);
    }
    void help(TreeNode *root, vector<int>&result,int cur)
	{
		if (root == nullptr)
			return;
		cur = cur * 10 + root->val;
		if (!(root->left) && !(root->right))
			result.push_back(cur);
		help(root->left, result, cur);
		help(root->right, result, cur);
	}
};

class Solution
{
public:
	int sumNumbers(TreeNode *root){
		return dfs(root,0);
	}
private:
	int dfs(TreeNode *root,int sum){
		if(root=nullptr)return 0;
		if(root->left==nullptr && root->right==nullptr)
			return sum*10+root->val;
		return dfs(root->left,sum*10+root->val)+
				dfs(root->right,sum*10+root->val);
	}
};
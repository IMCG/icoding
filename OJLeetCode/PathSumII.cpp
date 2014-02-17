class Solution {
public:
	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		vector<vector<int>>result;
		//思考为什么cur要写在这里。
		vector<int>cur;
		pathHelp(root, sum, cur, result);
		return result;
	}
	void pathHelp(TreeNode*root, int sum, vector<int>&cur,vector<vector<int>>&result)
	{
		if (root == nullptr)return;

		cur.push_back(root->val);
		if (!(root->left) && !(root->right)){
			if (sum == root->val)
				result.push_back(cur);
		}
		
		pathHelp(root->left, sum - root->val, cur, result);
		pathHelp(root->right, sum - root->val, cur, result);
		cur.pop_back();
	}
};
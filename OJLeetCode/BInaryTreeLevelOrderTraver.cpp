/*Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>>result;
        traval(root,1,result);
        return result;
    }
    void traval(TreeNode*root,size_t level,vector<vector<int>>&result)
    {
      if(root==nullptr)
        return;
      if(level>result.size())
        result.push_back(vector<int>());
      result[level-1].push_back(root->val);
      
      traval(root->left,level+1,result);
      traval(root->right,level+1,result);
    }
};
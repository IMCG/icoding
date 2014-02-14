/*Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along 
the shortest path from the root node down to the nearest leaf node.
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
    int minDepth(TreeNode *root) {
        if(root==nullptr)
            return 0;
        int left=minDepth(root->left);
        int right=minDepth(root->right);
        if(!root->left && !root->right)
            return 1;
        if(!root->right)
            return left+1;
        if(!root->left)
            return right+1;
        else
            return min(left,right)+1;
    }
};
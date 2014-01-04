/*Binary Tree Preorder Traversal 
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        if(root==nullptr)return result;
        stack<TreeNode*>st;
        TreeNode*cur=root;
        st.push(cur);
        
        while(!st.empty()){
            cur=st.top();
            st.pop();
            result.push_back(cur->val);
            if(cur->right)
                st.push(cur->right);
            if(cur->left)
                st.push(cur->left);
        }
        return result;
    }
};
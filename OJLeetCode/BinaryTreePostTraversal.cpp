/*Binary Tree Postorder Traversal 
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?

Discuss

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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        if(root==nullptr)return result;
        stack<TreeNode*>st;
        TreeNode*cur=root;
        TreeNode*tag;
        do{
            while(cur!=nullptr){
                st.push(cur);
                cur=cur->left;
            }
            tag=nullptr;
            while(!st.empty())
            {
                cur=st.top();
                st.pop();
                if(cur->right==tag){
                    result.push_back(cur->val);
                    tag=cur;
                }
                else
                {
                    st.push(cur);
                    cur=cur->right;
                    break;
                }
            }
        }while(!st.empty());
        return result;
    }
};
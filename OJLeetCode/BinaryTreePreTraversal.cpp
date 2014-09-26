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
//AC
//Morris  只有输出顺序和inorder不同
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        if(root==nullptr)return vector<int>();
        TreeNode *cur = root;
        vector<int> result;
        TreeNode *pre = nullptr;
        while(cur != nullptr){
            if(cur->left == nullptr){
                result.push_back(cur->val);
                cur = cur->right;
            }
            else
            {
                pre = cur->left;
                while(pre->right!=nullptr && pre->right!=cur)
                    pre = pre->right;

                if(pre->right==nullptr){
                    result.push_back(cur->val);
                    pre->right = cur;
                    cur = cur->left;
                }else{
                    //for inorder
                    //result.push_back(cur->val);
                    pre->right = nullptr;
                    cur = cur->right;
                }
            }
       }
       return result;
    }
};
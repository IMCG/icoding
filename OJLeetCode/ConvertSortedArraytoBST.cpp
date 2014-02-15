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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        int start=0;
        int end=num.size()-1;
        return addToTree(num,start,end);   
    }
private:
    TreeNode *addToTree(vector<int>&num,int start,int end)
    {
        if(start>end)
            return nullptr;
        int mid=(start+end)/2;
        TreeNode*head=new TreeNode(num[mid]);
        head->left=addToTree(num,start,mid-1);
        head->right=addToTree(num,mid+1,end);
        return head;
    }
};
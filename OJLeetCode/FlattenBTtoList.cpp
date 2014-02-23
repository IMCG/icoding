/*Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
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
 //有bug
class Solution {
public:
    void flatten(TreeNode *root) {
        if(root==nullptr)return;
        TreeNode dummy(0);
		TreeNode*result = &dummy;
		stack<TreeNode*>st;
		st.push(root);
		TreeNode*cur = nullptr;
		while (!st.empty())
		{
			cur = st.top();
			st.pop();
			result->right = newNode(cur->val);
			result=result->right;
			if (cur->right)
				st.push(cur->right);
			if (cur->left)
				st.push(cur->left);
		}
		root = dummy.right;
    }
    TreeNode*newNode(int elem){
		TreeNode*cur = new TreeNode(elem);
		cur->left=nullptr;
		cur->right=nullptr;
		return cur;
	}
};
//直接指向下一个要出来的TreeNode.迭代版
class Solution {
public:
    void flatten(TreeNode *root) {
        if(root==nullptr)return;
		stack<TreeNode*>st;
		st.push(root);
		while (!st.empty())
		{
			auto cur = st.top();
			st.pop();
			if (cur->right)
				st.push(cur->right);
			if (cur->left)
				st.push(cur->left);
			cur->left=nullptr;
			if(!st.empty())
			    cur->right=st.top();
		}
    }
};
//递归版
void flatten(TreeNode* root){
	if(root==nullptr)return;

	flatten(root->left);
	flatten(root->right);

	//合并
	TreeNode *p=root->left;
	while(p->right)p=p->right;//左子树最右节点。
	p->right=root->right;
	root->right=root->left;
	root->left=nullptr;
}
//@2
class Solution{
public:
	void flatten(TreeNode*root){
		flatten(root,nullptr);
	}
private://把root所代表树变成链表后，tail跟在改链表后面
	TreeNode *flatten(TreeNode *root,TreeNode *tail){
		if(root==nullptr)return tail;

		root->right=flatten(root->left,flatten(root->right,tail));
		root->left=nullptr;
		return root;
	}
};
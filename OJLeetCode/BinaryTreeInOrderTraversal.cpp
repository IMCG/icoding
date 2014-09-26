#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode*newNode(int elem)
{
	TreeNode*cur = new TreeNode(elem);
	cur->left = nullptr;
	cur->right = nullptr;
	return cur;
}
TreeNode*InsertNode(TreeNode*head, int elem)
{
	if (head == nullptr)return newNode(elem);
	else if (elem < head->val)
		head->left = InsertNode(head->left, elem);
	else
		head->right = InsertNode(head->right, elem);
	return head;
}
//头脑清晰。。
class Solution {
public:
	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> result;
		if (root == nullptr)
			return result;
		TreeNode*p=root;
		stack<TreeNode*> st;
		while(!st.empty()||p)
		{
		    if(p){
		        st.push(p);
		        p=p->left;
		    }
		    else
		    {
		        p=st.top();
		        st.pop();
		        result.push_back(p->val);
		        p=p->right;
		    }
		}
		return result;
	}
};

int main()
{
	/*int A[8] = { 5, 3, 8, 1, 4, 7, 9, 6 };
	TreeNode*head = nullptr;
	for (int i = 0; i < 8; i++)
		head = InsertNode(head, A[i]);*/
	TreeNode*head = new TreeNode(1);
	head->left = new TreeNode(2);
	Solution s;
	vector<int> result = s.inorderTraversal(head);
	for (auto& i : result)
	{
		cout << i << " ";
	}
	cout << endl;
}

//Morris inorderTraversal
/*1. Initialize current as root
  2. While current is not NULL
      If current does not have left child     
       a. Print current’s data
       b. Go to the right, i.e., current = current->right
      Else
       a. In current's left subtree, make current the right child of the rightmost node
       b. Go to this left child, i.e., current = current->left*/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //AC
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
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
       				pre->right = cur;
       				cur = cur->left;
       			//因为 前驱->cur  已经访问过了,撤销线索
       			}else{
       				result.push_back(cur->val);
       				pre->right = nullptr;
       				cur = cur->right;
       			}
       		}
       }
       return result;
    }
};
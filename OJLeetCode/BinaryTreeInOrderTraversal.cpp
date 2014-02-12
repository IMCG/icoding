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
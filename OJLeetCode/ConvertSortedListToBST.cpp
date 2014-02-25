//Given a singly linked list where elements are sorted in ascending order, 
//convert it to a height balanced BST.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == nullptr)return nullptr;
		vector<int>tmp;
		ListNode*cur = nullptr;
		while (head){
			cur = head;
			tmp.push_back(cur->val);
			head = head->next;
		}
		TreeNode*tree = ArrayToBST(tmp, 0, tmp.size() - 1);
		return tree;
    }
private:
	TreeNode *ArrayToBST(vector<int>&tmp, int left, int right)
	{
		//使用递归都需要初始条件的判定。
		if (left > right)return nullptr;
		int mid = (left + right) / 2;
		TreeNode*head = new TreeNode(tmp[mid]);
		head->left = ArrayToBST(tmp, left, mid - 1);
		head->right = ArrayToBST(tmp, mid + 1, right);
		return head;
	}
};
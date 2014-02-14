/*Date:2014/2/14
@Author:icodingc
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void push(ListNode*&root, int elem)
{
	ListNode*cur = new ListNode(elem);
	cur->next = root;
	root = cur;
}
void print(ListNode*root)
{
	while (root)
	{
		cout << root->val << " ";
		root = root->next;
	}
	cout << endl;
}
/*考虑特殊情况[1,1,1]  [1,1,2]
*/
class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode*prev = head;
		ListNode*cur = head->next;
		ListNode*tmp = nullptr;
		while (cur)
		{
			if (prev->val == cur->val)
			{
				tmp = cur->next;
				prev->next = tmp;
				//free(cur);
				if (tmp == nullptr)
					break;
				cur= tmp;
			}
			else{
				cur = cur->next;
				prev = prev->next;
			}
		}
		return head;
	}
};
int main()
{
	ListNode*head = nullptr;
	//push(head, 3);
	//push(head, 3);
	push(head, 2);
	push(head, 1);
	push(head, 1);

	print(head);
	Solution s;
	head = s.deleteDuplicates(head);
	print(head);

	return 0;
};

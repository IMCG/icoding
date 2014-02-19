/*
Given a linked list, remove the nth node from the end of list and return 
its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list
    becomes 1->2->3->5.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		if (!head || !(head->next) && n > 0)
			return nullptr;
		int i = 1;
		ListNode*first = head;
		ListNode*last = head;
		while (first && i <= n){
			first = first->next;
			i++;
		}
		if (!first)
			return head->next;
		while (first->next){
			first = first->next;
			last = last->next;
		}
		last->next = last->next->next;
		return head;
	}
};
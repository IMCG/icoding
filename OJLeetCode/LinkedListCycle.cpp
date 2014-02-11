/*Linked List Cycle Total 
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
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
    bool hasCycle(ListNode *head) {
        if(head==nullptr)return false;
  		//head->next---->head.
        ListNode*fast = head;
		ListNode*slow = head;

		while (fast != nullptr){
			fast = fast->next;
			if (fast != nullptr){
				fast = fast->next;
				slow = slow->next;
			}
			if (fast == slow)
				return true;
		}
		return false;
    }
};
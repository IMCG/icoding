/*Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/
//递归
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
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next)return head;
		ListNode*p = head->next;
		if (head->val == p->val){
			while (p&&head->val == p->val){
				ListNode*tmp = p;
				p = p->next;
				delete tmp;
			}
			delete head;
			return deleteDuplicates(p);
		}
		else{
			head->next = deleteDuplicates(head->next);
			return head;
		}
    }
};
//迭代
class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (head == nullptr)return head;
		ListNode dummy(0);
		dummy.next = head;
		ListNode*prev = &dummy, *cur = head;
		while (cur != nullptr){
			bool dup = false;
			while (cur->next != nullptr &&cur->val == cur->next->val){
				dup = true;
				ListNode*tmp = cur;
				cur = cur->next;
				delete tmp;
			}
			if (dup){
				//删除重复的最后一个元素
				ListNode*temp = cur;
				cur = cur->next;
				delete temp;
				continue;
			}
			prev->next = cur;
			prev = prev->next;
			cur = cur->next;
		}
		prev->next = cur;
		return dummy.next;
	}
};

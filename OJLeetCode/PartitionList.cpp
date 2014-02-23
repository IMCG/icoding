/*Given a linked list and a value x, partition it such that all nodes less than x come 
before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/
//出错了。
class Solution {
public:
	ListNode *partition(ListNode *head, int x) {
		if (head == nullptr)return head;
		ListNode*cur = head;
		ListNode*result = head;
		bool sign = true;
		while (head){
			if (head->val < 3){
				if (sign)
				{
					result = result->next;
					head = head->next;
					sign = !sign;
					continue;
				}
				else{
					move(result, head);
					result = result->next;
				}
			}
			else
				head = head->next;
		}
		return head;
	}
	void move(ListNode*&aRef, ListNode*&bRef)
	{
		if (bRef == nullptr)return;
		ListNode*cur = bRef;
		bRef = cur->next;
		cur->next = aRef;
		aRef = cur;
	}
};

class Solution {
public:
	ListNode* partition(ListNode* head, int x){
		if (head == nullptr)return head;
		ListNode left_dummy(0);
		ListNode right_dummy(0);
		auto left_cur = &left_dummy;
		auto right_cur = &right_dummy;
		for (; head; head = head->next){
			if (head->val < x){
				left_cur->next = head;
				left_cur = head;
			}
			else{
				right_cur->next = head;
				right_cur = head;
			}
		}
		left_cur->next = right_dummy.next;
		right_cur->next = nullptr;
		return left_dummy.next;
	}
};
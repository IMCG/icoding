#include<iostream>
using namespace std;

 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 ListNode*Push(ListNode*&head, int elem)
 {
	 ListNode*cur = new ListNode(elem);
	 cur->next = head;
	 return cur;
 }
 void Print(ListNode*head)
 {
	 while (head)
	 {
		 cout << head->val << " ";
		 head = head->next;
	 }
	 cout << endl;
 }
class Solution {
public:
	ListNode *sortList(ListNode *head) {
		if (!head||!(head->next))return head;
		ListNode*fast = head, *slow = head;
		while (fast->next&&fast->next->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		//断开
		fast = slow;
		slow = slow->next;
		fast->next = nullptr;

		ListNode* a=sortList(head);
		ListNode* b=sortList(slow);
		return mergeTwoList(a, b);
	}
	ListNode *mergeTwoList(ListNode* a, ListNode*b)
	{
		ListNode dummy(0), *cur = &dummy;
		for (;a||b; cur = cur->next)
		{
			int val1 = a == nullptr ? INT_MAX : a->val;
			int val2 = b == nullptr ? INT_MAX : b->val;
			if (val1 < val2){
				cur->next = a;
				a = a->next;
			}
			else{
				cur->next = b;
				b = b->next;
			}
		}
		return dummy.next;
	}
};
int main()
{
	int a[] = { 3, 7, 4, 9, 5, 6, 5, 8, 6 };
	ListNode*head = nullptr;
	for (auto& i : a)
	{
		head = Push(head, i);
	}
	Print(head);
	ListNode*cur = nullptr;
	Solution s;
	cur = s.sortList(head);
	Print(cur);
	return 0;
}
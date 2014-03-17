/*File:LinkList.h
 *a help file to coding.
 *lots of functions with list.
 */

#ifndef _linklist_h
#define _linklist_h

#include <iostream>
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr){}
};

//push elem to List
ListNode*Push(ListNode*head, int elem){
	ListNode*cur = new ListNode(elem);
	cur->next = head;
	return cur;
}

/*add Two Numbers
 *2 4 3 + 5 6 4 ==>7 0 8
 */
ListNode *AddTwoNumbers(ListNode *l1, ListNode *l2){
	ListNode dummy(-1);
	int carry = 0;
	ListNode*cur = &dummy;
	for (; l1 || l2;
		l1 = l1 == nullptr ? nullptr : l1->next,
		l2 = l2 == nullptr ? nullptr : l2->next,
		cur = cur->next){
		const int val1 = l1 == nullptr ? 0 : l1->val;
		const int val2 = l2 == nullptr ? 0 : l2->val;
		int sum = (val1 + val2 + carry) % 10;
		carry = (val1 + val2 + carry) / 10;
		cur->next = new ListNode(sum);
	};
	if (carry > 0)
		cur = new ListNode(carry);
	return dummy.next;
}

//print the list
void Print(ListNode *head){
	while (head){
		std::cout << head->val << " ";
		head = head->next;
	}
	std::cout << std::endl;
}

//insert the node to sorted list
void SortedInsert(ListNode*&head, ListNode*aRef){
	ListNode dummy(0);
	ListNode*cur = &dummy;
	dummy.next = head;
	while (cur->next&&cur->next->val < aRef->val)
		cur = cur->next;

	aRef->next = cur->next;
	cur->next = aRef;

	head = dummy.next;
}

//insertionSort
ListNode *insertionSort(ListNode*head){
	ListNode*result = nullptr;
	ListNode*cur = nullptr;
	
	while (head){
		cur = head->next;
		SortedInsert(result, head);
		head = cur;
	}
	return result;
}

//MergeSorted
ListNode *mergeTwoList(ListNode* a, ListNode*b)
{
	ListNode dummy(0), *cur = &dummy;
	for (; a || b; cur = cur->next)
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

//SortMerge
ListNode *sortList(ListNode *head) {
	if (!head || !(head->next))return head;
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

	ListNode* a = sortList(head);
	ListNode* b = sortList(slow);
	return mergeTwoList(a, b);
}

#endif
//插入排序超时
void SortedInsert2(ListNode*&head, ListNode*aRef)
{
	ListNode dummy;
	ListNode*cur = &dummy;
	dummy.next = head;

	while (cur->next && cur->next->val < aRef->val)
		cur = cur->next;
	aRef->next = cur->next;
	cur->next = aRef;

	head = dummy.next;
}
ListNode* sortLinkList(ListNode *head) {
	ListNode*cur = nullptr;
	ListNode*result = nullptr;
	while (head){
		cur = head->next;
		SortedInsert2(result, head);
		head = cur;
	}
	return result;
}
//归并排序
ListNode *MergeSorted(ListNode*a, ListNode*b){
	ListNode dummy;
	ListNode*cur = &dummy;
	for (; a || b; cur = cur->next){
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

ListNode* sortLinkList(ListNode *head) {
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

	ListNode* a = sortLinkList(head);
	ListNode* b = sortLinkList(slow);
	return MergeSorted(a, b);
}
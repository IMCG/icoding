//Sort a linked list using insertion sort.
#include<iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode*next;
	ListNode(int x) :val(x), next(nullptr){}
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
class Solution{
public:
	ListNode *insertionSort(ListNode*head)
	{
		ListNode*result = nullptr;
		ListNode*cur = nullptr;
		while (head)
		{
			cur = head->next;
			SortedInsert1(result, head);
			head = cur;
		}
		return result;
	}
	void SortedInsert(ListNode*&head, ListNode*aRef)
	{
		if (head==nullptr || head->val > aRef->val)
		{
			aRef->next = head;
			head = aRef;
		}
		else
		{
			//必须引入变量,因为head必须从头开始
			ListNode*cur = head;
			while (cur->next && cur->next->val< aRef->val){
				cur = cur->next;
			}
			aRef->next = cur->next;
			cur->next = aRef;
		}	
	}
	void SortedInsert1(ListNode*&head, ListNode*aRef)
	{
		ListNode result(0);
		ListNode* cur = &result;
		result.next = head;
		//error....while+if==>while(&&)..
		while (cur->next)
		{
			if (cur->next->val > aRef->val)
			{
				aRef->next = cur->next;
				cur->next = aRef;
				//不是return;
				break;
			}
			cur = cur->next;
		}
		head = result.next;
	}
	void SortedInsert2(ListNode*&head, ListNode*aRef)
	{
		ListNode dummy(0);
		ListNode*cur = &dummy;
		dummy.next = head;

		while (cur->next && cur->next->val < aRef->val)
			cur = cur->next;
		aRef->next = cur->next;
		cur->next = aRef;

		head = dummy.next;
	}
};
class Solution{
public:
	ListNode *insertionSortList(ListNode*head)
	{
		ListNode dummy(0);
		//dummy.next = head;
		for (ListNode*cur = head; cur != nullptr;)
		{
			auto pos = findInsertPos(&dummy, cur->val);
			ListNode*tmp = cur->next;
			cur->next = pos->next;
			pos->next = cur;
			cur = tmp;
		}
		return dummy.next;
	}
	ListNode*findInsertPos(ListNode*head, int x)
	{
		ListNode*pre = nullptr;
		for (ListNode*cur = head; cur != nullptr && cur->val <= x;
			pre=cur,cur = cur->next)
			;
		return pre;
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
	cur = s.insertionSort(head);
	if (cur == nullptr)
		cout << "empty";
	else
		cout << "Unempty" << endl;
	Print(cur);

	return 0;
}
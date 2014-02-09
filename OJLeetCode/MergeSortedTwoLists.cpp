//Merge Two Sorted Lists
#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};
ListNode*Push(ListNode*&head, int elem)
{
	ListNode*cur = new ListNode(elem);
	cur->next = head;
	return cur;
}
//关键点：cur=&result.  cur->next=new ....;
ListNode *MergeTwoLists(ListNode *l1, ListNode *l2)
{
	ListNode result(-1);
	//ListNode result(-1);
	for (ListNode*cur = &result; l1 || l2; cur = cur->next)
	{
		int val1 = l1 == nullptr ? INT_MAX : l1->val;
		int val2 = l2 == nullptr ? INT_MAX : l2->val;
		if (val1 < val2){
			cur->next = new ListNode(val1);
			//cur->next = l1; 机智。。
			l1 = l1->next;
		}
		else{
			cur->next = new ListNode(val2);
			//cur->next = l2;
			l2 = l2->next;
		}	
	}
	return result.next;
}
//Using dummy node
ListNode *MergeTwoLists1(ListNode *l1,ListNode *l2)
{
	ListNode head(0);
	ListNode *cur=&head;
	while(l1&&l2)
	{
		int val1=l1->val;
		int val2=l2->val;
		if(val1<val2){
			cur->next=l1;
			l1=l1->next;
		}else{
			cur->next=l2;
			l2=l2-next;
		}
		cur=cur-next;
	}
	// while(l1&&l2)
	// {
	// 	ListNode**min=l1->val<l2->val?&l1:&l2;
	// 	cur->next=*min;
	// 	cur=cur-next;
	// 	*min=(*min)->next;
	// }
	if(l1)
		cur->next=l1;
	if(l2)
		cur->next=l2;
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
int main()
{
	int a[4] = { 7, 5, 3, 1 };
	int b[4] = { 8, 6, 4, 2 };
	ListNode*aRef = nullptr;
	ListNode*bRef = nullptr;
	ListNode*cRef = nullptr;
	for (auto& i : a)
	{
		aRef = Push(aRef, i);
	}
	for (auto& i : b)
	{
		bRef = Push(bRef, i);
	}
	Print(aRef);
	Print(bRef);

	cRef = MergeTwoLists(aRef, bRef);
	Print(cRef);
	if (cRef == nullptr)
		cout << "empty";
	else
		cout << "Unempty";

	return 0;
}
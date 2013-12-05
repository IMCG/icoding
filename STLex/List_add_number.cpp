#include<iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode*next;
	ListNode(int x):val(x),next(nullptr){}
};
class Solution
{
public:
	ListNode*AddDoubleList(ListNode *L1,ListNode *L2)
	{
		ListNode dummy(-1);
		ListNode *current=&dummy;
		int carry=0;
		for(ListNode *pa=L1,*pb=L2;pa!=nullptr||pb!=nullptr;
			pa=pa==nullptr?nullptr:pa->next,
			pb=pb==nullptr?nullptr:pb->next,
			current=current->next)
		{
			const int a1=pa==nullptr?0:pa->val;
			const int a2=pb==nullptr?0:pb->val;
			int value=(a1+a2+carry)%10;
			current->next=new ListNode(value);
			carry=(a1+a2+carry)/10;
		}
		if(carry>0)
			current->next=new ListNode(carry);
		return dummy.next;
	}
};
void Push(ListNode *&head,int elem)
{
	ListNode*temp=new ListNode(elem);
	temp->next=head;
	head=temp;
}
void Print(ListNode *head)
{
	while(head)
	{
		cout<<head->val<<" ";
		head=head->next;
	}
	cout<<endl;
}
int main()
{
	ListNode*L1=NULL;
	ListNode*L2=NULL;
	Push(L1,3);
	Push(L1,4);
	Push(L1,2);
	Push(L2,4);
	Push(L2,6);
	Push(L2,5);
	Print(L1);
	Print(L2);
	Solution s;
	ListNode*head=s.AddDoubleList(L1,L2);
	Print(head);
}

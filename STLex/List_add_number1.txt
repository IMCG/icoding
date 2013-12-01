#include<iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode*next;
	ListNode(int x):val(x),next(nullptr){}
};
void Push(ListNode *&head,int elem)
{
	ListNode*temp=new ListNode(elem);
	temp->next=head;
	head=temp;
}
ListNode*AddTwo(ListNode*L1,ListNode*L2)
	{
		ListNode*head=NULL;
		ListNode*tail,*pa=L1,*pb=L2;
		Push(head,0);
		tail=head;
		int carry=0;
		while(pa!=nullptr || pb!=nullptr)
		{
			int a1=pa==nullptr?0:pa->val;
			int a2=pb==nullptr?0:pb->val;
			int value=(a1+a2+carry)%10;
			carry=(a1+a2+carry)/10;
			Push(tail->next,value);

			pa=pa==nullptr?nullptr:pa->next;
			pb=pb==nullptr?nullptr:pb->next;
			tail=tail->next;
		}
		if(carry>0)
			Push(tail->next,carry);
		return head;
	}
void DeleteList(ListNode*&head)
{
	ListNode*current=head->next;;
	free(head);
	head=current;
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
	Push(L1,8);
	Push(L1,9);
	//Push(L1,2);
	Push(L2,1);
	/*Push(L2,6);
	Push(L2,5);*/
	Print(L1);
	Print(L2);
	ListNode*head=AddTwo(L1,L2);
	DeleteList(head);
	Print(head);
}

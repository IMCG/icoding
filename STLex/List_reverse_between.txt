#include<iostream>
#include<vector>
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

ListNode *reverseBetween1(ListNode *head, int m, int n) {  
        vector<ListNode*> range(n - m + 1);  
          
        ListNode* iter = head;  
        for(int i = 1; i < m; ++i)  
            iter = iter->next;  
              
        for(int i = m, j = 0; i <= n; ++i, ++j)  
        {  
            range[j] = iter;  
            iter = iter->next;  
        }  
          
        for(size_t i = 0; i < range.size() / 2; ++i)  
            swap(range[i]->val, range[range.size() - i - 1]->val);  
          
        return head;  
    }  
ListNode*reverseBetween(ListNode *&head, int m, int n)
{
	ListNode dummy(-1);
	dummy.next=head;

	ListNode *prev_m=NULL,*prev=&dummy;
	for(int i=1;i<=n;i++)
	{
		if(i==m) prev_m=prev;

		if(i>m&&i<=n)//prev_m and prev static
		{
			prev->next=head->next;
			head->next=prev_m->next;
			prev_m->next=head;
			head=prev;
		}
		prev=head;
		head=head->next;
	}
	return dummy.next;

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
	ListNode*head=NULL;
	Push(head,6);
	Push(head,5);
	Push(head,4);
	Push(head,3);
	Push(head,2);
	Push(head,1);
	Print(head);
	head=reverseBetween1(head,2,5);
	Print(head);
}

//List 
#include<iostream>
using namespace std;

typedef struct node{
	int data;
	node *next;
}node;

node *init(int a[],int n)
{
	node *head=NULL;
	node *p=NULL;
	for(int i=0;i<n;i++)
	{
		node *nd=new node();
		nd->data=a[i];
		if(i==0)
		{
			head=p=nd;
			continue;
		}
		p->next=nd;
		p=nd;
	}
	return head;
}
void print_list(node *head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}
void reverse_print(node*head)
{
	if(head==NULL) return;

	reverse_print(head->next);
	cout<<head->data<<" ";
}
void print_alter_list(node *head)
{
	if(head==NULL) return;
	cout<<head->data<<" ";
	if(head->next!=NULL)
	  print_alter_list(head->next->next);
	cout<<head->data<<" ";
}
void push_list(node **head,int elem)
{
	node *nd=new node();
	nd->data=elem;
	nd->next=*head;
	*head=nd;
}
int main()
{
	/*int a[]={2,1,5,3,8};
	int n=5;
	node*head=init(a,n);
	print_list(head);
	cout<<"reverse....."<<endl;
	reverse_print(head);
	cout<<endl;*/
	node *head=NULL;
	for(int i=1;i<=6;i++)
	{
		push_list(&head,i);
	}
	print_list(head);
	reverse_print(head);
	cout<<endl;
	print_alter_list(head);
	cout<<endl;
}
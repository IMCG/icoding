#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct node{
	int data;
	node* next;
}node;
node* init(int a[],int n)
{
	node *head=NULL,*p=NULL;
	for(int i=0;i<n;i++)
	{
		node *nd=new node();
		nd->data=a[i];
		if(i==0){
			head=p=nd;
			continue;
		}
		p->next=nd;
		p=nd;
	}
	return head;
}
void print(node *head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}
void fun1(node *head)
{
	if(head==NULL) return;
	fun1(head->next);
	cout<<head->data<<" ";
}
int main()
{
	int n=5;
	int a[]={1,2,3,4,5};
	node *head=init(a,n);
	print(head);
	fun1(head);
	return 0;
}
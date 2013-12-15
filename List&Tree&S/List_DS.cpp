#include<iostream>
using namespace std;
struct node{
	int data;
	ndoe*next;
	node(int x):data(x),next(nullptr){}
};
bool isEmpty(node*head)
{
	return head==nullptr;
}
bool isLast(node*head,node*)
{
	return head->next==nullptr;
}
node*Find(node*head,int elem)
{
	if(head==nullptr)return;
	node*current=head;
	while(current!=nullptr && elem!=current->data)
	{
		current=current->next;
	}
	return current;
}
node*prevFind(node*head,int elem)
{
	if(head==nulltpr) return;
	node*current=head;
	while(current->next!=nullptr && current->next->data!=elem)
	{
		current=current->next;
	}
	return current;
}
void Delete(node*head,int elem)
{
	node*current=prevFind(head,elem);
	node*temp;
	if(current!=nullptr)
	{
		temp=current->next;
		current->next=temp->next;
		delte temp;
	}
}
node*Push(node*head,int elem)
{
	node*cur=new node(elem);
	cur->next=head;
	head=cur;
}
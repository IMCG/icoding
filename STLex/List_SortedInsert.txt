#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};
//One
void SortedInsert(struct node**headRef,struct node*newNode)
{
	if(*headRef==NULL || (*headRef)->data>=newNode->data)
	{
		newNode->next=*headRef;
		*headRef=newNode;
	}else{
		struct node*current=*headRef;
		while(current->next!=NULL && current->next->data<newNode->data)
		{
			current=current->next;
		}
		newNode->next=current->next;
		current->next=newNode;
	}
}
//Dummy node
void SortedInsert(struct node**headRef,struct node*newNode)
{
	struct node dummy;
	struct node*current=&dummy;

	dummy.next=*headRef;
	while(current->next!=NULL && current->next->data<newNode->data)
		{
			current=current->next;
		}
		newNode->next=current->next;
		current->next=newNode;


		*headRef=dummy.next;
}
void SortedInsert(struct node**headRef,struct node*newNode)
{
	struct node**current=headRef;
	while((*current)!=NULL || (*current)->data < newNode->data)
	{
		current=&((*current)->next);
	}
	newNode->next=*current;
	*current=newNode;
}
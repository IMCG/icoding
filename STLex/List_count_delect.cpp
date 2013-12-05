#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
struct node{
	int data;
	struct node*next;
};
void Push(struct node**headRef,int elem)
{
	struct node*one=(struct node*)malloc(sizeof(struct node));
	one->data=elem;
	one->next=*headRef;
	*headRef=one;
}
int Length(struct node*head)
{
	int i=0;
	while(head)
	{
		head=head->next;
		++i;
	}
	return i;
}
struct node*BuildList()
{
	struct node*head=NULL;
	Push(&head,2);
	Push(&head,1);
	Push(&head,2);
	Push(&head,4);
	Push(&head,6);
	Push(&head,2);
	return head;
}
int Count(struct node*head,int searchFor)
{
	int count=0;
	struct node*current=head;
	while(current!=NULL)
	{
		if(current->data==searchFor){
			++count;
		}
		current=current->next;
	}
	return count;
}
int GetNth(struct node*head,int index)
{
	assert(index<Length(head));
	struct node*current=head;
	int i=0;
	while(i<index)
	{
		current=current->next;
		++i;
	}
	return current->data;
	/*while(current!=NULL)
	{
		if(i==index) return current->data;
		++i;
		current=current->next;
	}*/
}
//good double pointer.
void DeleteList(struct node**headRef)
{
	struct node*current=*headRef;
	struct node*next;

	while(current!=NULL)
	{
		next=current->next;
		free(current);
		current=next;
	}
	*headRef=NULL;
}
int CountTest()
{
	struct node*head=BuildList();
	int count=Count(head,2);
	return count;
}
int GetNthTest()
{
	struct node*head=BuildList();
	int value=GetNth(head,2);
	return value;
}
struct node* DeleteListTest()
{
	struct node*head=BuildList();
	DeleteList(&head);
	return head;
}
int main()
{
	struct node*head=DeleteListTest();
	printf("%d", Length(head));
	/*struct node*head=BuildList();
	printf("%d",Length(head));*/
}
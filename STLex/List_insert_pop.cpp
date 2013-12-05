#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
struct node {
	int data;
	struct node*next;
};
struct node*BuildOneTwoThree()
{
	struct node*One=(struct node*)malloc(sizeof(struct node));
	struct node*Two=(struct node*)malloc(sizeof(struct node));
	struct node*Three=(struct node*)malloc(sizeof(struct node));
	One->data=1;
	One->next=Two;
	Two->data=2;
	Two->next=Three;
	Three->data=3;
	Three->next=NULL;
	return One;
}
void Push(struct node**headRef,int elem)
{
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	temp->data=elem;
	temp->next=*headRef;
	*headRef=temp;
}
int length(struct node*head)
{
	struct node*current=head;
	int count=0;
	while(current!=NULL)
	{
		++count;
		current=current->next;
	}
	return count;
}
int Pop(struct node**headRef)
{
	int res;
	struct node*head;
	head=*headRef;
	assert(*headRef!=NULL);
	res=head->data;
	*headRef=head->next;
	free(head);
	return res;
}
void Print(struct node*head)
{
	struct node*current=head;
	while(current!=NULL)
	{
		printf("%d  ",current->data);
		current=current->next;
	}
	printf("\n");
}
void InsertNth(struct node**headRef,int index,int elem)
{
	struct node*current=*headRef;
	int count=0;
	if(index>0){
		while(current!=NULL)
		{
			if(count==index-1)
			{
				/*struct node*temp=(struct node*)malloc(sizeof(struct node));
				temp->data=elem;
				temp->next=current->next;
				current->next=temp;*/
				Push(&(current->next),elem);
			}
			count++;
			current=current->next;
		}
	}
	else if(index==0)
	{
		/*(*headRef)->data=elem;
		(*headRef)->next=NULL;*/
		Push(headRef,elem);
	}
	
}
int main()
{
	struct node*head=NULL;
	InsertNth(&head,0,13);
	InsertNth(&head,1,42);
	InsertNth(&head,1,5);
	printf("len=%d\n",length(head));
	Print(head);
}
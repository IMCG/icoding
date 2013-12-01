#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};
void Push(struct node**head,int elem)
{
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	temp->data=elem;
	temp->next=*head;
	*head=temp;
}
void Print(struct node*head){
	struct node*current=head;
	while(current!=NULL)
	{
		printf("%d ",current->data);
		current=current->next;
	}
	printf("\n");
}
void SortedInsert(struct node**headRef,struct node*newNode)
{
	struct node*current=*headRef;
	if(*headRef==NULL || (*headRef)->data >= newNode->data)
	{
		newNode->next=*headRef;
		*headRef=newNode;
	}else{
		while(current->next !=NULL && current->next->data < newNode->data)
		{	
			current=current->next;
		}
		newNode->next=current->next;
		current->next=newNode;
	}
}

void InsertSort(struct node**headRef)
{
	struct node*result=NULL;
	struct node*current=*headRef;
	struct node*next;
	while(current!=NULL)
	{
		//move node's trick(delete)
		next=current->next;
		SortedInsert(&result,current);
		current=next;
	}
	*headRef=result;
}
int main()
{
	int A[6]={6,2,8,4,9,5};
	//int A[6]={1,2,3,5,6,7};
	struct node*head=NULL;
	for(int i=5;i>=0;i--)
	{
		Push(&head,A[i]);
	}
	Print(head);
	printf("Sorted........\n");
	InsertSort(&head);
	/*struct node*tmp=(struct node*)malloc(sizeof(struct node));
	tmp->data=4;
	SortedInsert(&head,tmp);*/
	Print(head);
}
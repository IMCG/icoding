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
void Print(struct node*head)
{
	while(head)
	{
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
}
void InsertSorted(struct node**headRef,struct node*newNode)
{
	struct node dummy;
	struct node*current=&dummy;
	dummy.next=*headRef;
	while(current->next!=NULL && current->next->data < newNode->data)
	{
		current=current->next;
	}
	newNode->next=current->next;
	current->next=newNode;

	*headRef=dummy.next;
}
void SortInsert(struct node**headRef)
{
	if(*headRef==NULL) return;
	struct node*result=NULL;
	struct node*cur_next;
	struct node*current=*headRef;

	while(current->next!=NULL)
	{
		cur_next=current->next;
		InsertSorted(&result,current);

		current=cur_next;
	}
	*headRef=result;
}
void Append(struct node**aRef,struct node**bRef)
{
	if(*aRef==NULL)  *aRef=*bRef;
	else{
		struct node*current=*aRef;
		while(current->next!=NULL)
		{
			current=current->next;
		}
		current->next=*bRef;
	}
	*bRef=NULL;
}
void FrontBackSplit(struct node*source,struct node**aRef,struct node**bRef)
{
	struct node*slow;
	struct node*fast;
    if(source==NULL || source->next==NULL)
	{
		*aRef=source;
		*bRef=NULL;
	}
	else{
		slow=source;
		fast=source->next;
		while(fast!=NULL)
		{
			fast=fast->next;
			if(fast!=NULL)
			{
				fast=fast->next;
				slow=slow->next;
			}
		}
		*aRef=source;
		*bRef=slow->next;
		slow->next=NULL;
	}
}
void RemoveDuplicate(struct node*head)
{
	struct node*current=head;
	if(current==NULL) return;
	struct node*next;
	while(current->next!=NULL)
	{
		next=current->next;
		if(current->data == next->data)
		{
			current->next=next->next;
		}else{
			current=current->next;
		}
	}
}
void MoveNode(struct node**destRef,struct node**sourceRef)
{
	if(*sourceRef==NULL)return;
	struct node*current=*sourceRef;

	*sourceRef=current->next;
	current->next=*destRef;
	*destRef=current;
}
void AlternatingSplit(struct node*sourse,struct node**aRef,struct node**bRef)
{
	struct node*current=sourse;
	if(current==NULL)return;
	//don't use current->next!=NULL
	while(current!=NULL)
	{
		int move_data=current->data;
		//struct node*next=current->next;
		if(IsEven(move_data))
		{
			MoveNode(aRef,&current);

		}else{
			MoveNode(bRef,&current);
		}
		//current->next=next->next;
	}
}
void AlternatingSplit1(struct node*sourse,struct node**aRef,struct node**bRef)
{
	struct node*current=sourse;
	while(current!=NULL)
	{
		MoveNode(aRef,&current);
		if(current!=NULL)
		{
			MoveNode(bRef,&current);
		}
	}
}
struct node*shuffleMerge1(struct node*a,struct node*b)
{
	//why errer
	struct node dummy;
	struct node*tail=&dummy;
	dummy.next=NULL;

	while(a!=NULL && b!=NULL)
	{
		MoveNode(&(tail->next),&a);
		tail=tail->next;
		MoveNode(&(tail->next),&b);
		tail=tail->next;
	}
	//this is the point.....not  while  but  if...
	if(a!=NULL)
		tail->next=a;
	if(b!=NULL)
		tail->next=b;
	return dummy.next;
}
struct node*shuffleMerge(struct node*a,struct node*b)
{
	struct node dummy;
	struct node*tail=&dummy;
	dummy.next=NULL;

	while(1)
	{
		if(a==NULL){
			tail->next=b;
		    break;
		}else if(b==NULL){
			tail->next=a;
			break;
		}else{
			tail->next=a;
			tail=a;
			a=a->next;
			tail->next=b;
			tail=b;
			b=b->next;
		}
	}
	return dummy.next;
}
struct node*shuffleMerge(struct node*a,struct node*b)
{
	struct node*result;
	struct node*recur;
	if(a==NULL) return b;
	else if(b==NULL) return a;
	else{
		recur=shuffleMerge(a->next,b->next);
		result=a;
		a->next=b;
		b->next=recur;
		return result;
	}
}
struct node*SortedMerge(struct node*aRef,struct node*bRef)
{
	struct node dummy;
	struct node*tail=&dummy;
	dummy.next=NULL;
	while(1)
	{
		if(aRef==NULL){
			tail->next=bRef;
			break;
		}else if(bRef==NULL){
			tail->next=aRef;
			break;
		}
		if(aRef->data <= bRef->data){
			MoveNode(&(tail->next),&aRef);
		}else{
			MoveNode(&(tail->next),&bRef);
		}
		tail=tail->next;
	}
	return dummy.next;
}
struct node*SortedMerge1(struct node*a,struct node*b)
{
	struct node*result=NULL;
	struct node**lastPtr=&result;

	while(1)
	{
		if(a==NULL)
		{
			*lastPtr=b;
			break;
		}else if(b==NULL)
		{
			*lastPtr=a;
			break;
		}

		if(a->data <= b->data)
		{
			MoveNode(lastPtr,&a);
		}else{
			MoveNode(lastPtr,&b);
		}
		lastPtr=&((*lastPtr)->next);
	}
	return result;
}
struct node*SortedMerge2(struct node*a,struct node*b)
{
	struct node*result=NULL;
	if(a==NULL) return b;
	else if(b==NULL) return a;

	if(a->data <= b->data )
	{
		result=a;
		result->next=SortedMerge2(a->next,b);
	}else{
		result=b;
		result->next=SortedMerge2(a,b->next);
	}
	return result;
}

int main()
{
	int A[6]={8,6,4,4,2,1};
	struct node*head=NULL;
	for(int i=5;i>=0;i--)
	{
		Push(&head,A[i]);
	}
	printf("aRef.....\n");
	Print(head);
	RemoveDuplicate(head);
	printf("Removed........\n");
	Print(head);
	/*struct node*add=(struct node*)malloc(sizeof(struct node));
	add->data=4;*/
  /* SortInsert(&head);
	Print(head);*/
	struct node*bRef=NULL;
	Push(&bRef,3);
	Push(&bRef,5);
	Push(&bRef,4);
	printf("bRef.........\n");
	Print(bRef);
	Append(&head,&bRef);

	printf("aRef.....\n");
	Print(head);
	printf("bRef.........\n");
	Print(bRef);
	struct node*a,*b;
	FrontBackSplit(head,&a,&b);

	printf("a.........\n");
	Print(a);
	printf("b.........\n");
	Print(b);

}

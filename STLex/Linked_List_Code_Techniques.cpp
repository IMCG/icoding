#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
/*Given a linked list head pointer,compute length*/
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
/*Build the list{1,2,3}*/
struct node*BuildOneTwoThree()
{
	struct node* One=(struct node*)malloc(sizeof(struct node));
	struct node* Two=(struct node*)malloc(sizeof(struct node));
	struct node* Three=(struct node*)malloc(sizeof(struct node));

	One->data=1;
	One->next=Two;

	Two->data=2;
	Two->next=Three;

	Three->data=3;
	Three->next=NULL;

	return One;
}
int LengthTest()
{
	struct node*mylist=BuildOneTwoThree();
	int len=length(mylist);
	return len;
}
void Push(struct node**headRef,int newData)
{
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	temp->data=newData;
	temp->next=*headRef;
	*headRef=temp;
}
struct node* PushTest()
{
	struct node*head=NULL;
	Push(&head,1);
	Push(&head,2);
	Push(&head,3);
	return head;
}
void print_list(struct node*head)
{
	while(head)
	{
		printf("%d\t",head->data);
		head=head->next;
	}
	printf("\n");
}
struct node* BasicsCaller()
{
	struct node*head=NULL;
	int len;
	head=BuildOneTwoThree();

	Push(&head,13);

	Push(&(head->next),24);
	len=length(head);
	return head;
}
/*1>Iterate Down a List
  2>Changing a Pointer Using a Reference Pointer(c_language)
  3>Build-At Head With Push()
  4>Build-With Tail Pointer
  5>Build-Special Case+Tail Pointer
  6>Build-Temporary Dummy Node(shorten the node)
  7>Build-Local References
*/
// Change the passed in head pointer to be NULL
// Uses a reference pointer to access the caller's memory
void ChangeToNull(struct node**headRef)
{
	*headRef=NULL;
}
void ChangeCaller()
{
	struct node*head1;
	struct node*head2;

	ChangeToNull(&head1);
	ChangeToNull(&head2);

}
struct node*AddAtHead()
{
	struct node*head;
	ChangeToNull(&head);
	for(int i=1;i<6;i++)
		Push(&head,i);
	return head;
}

//add nodes at the tail end of the list
struct node*BuildWithSpecialCase()
{
	struct node*head=NULL;
	struct node*tail;
	int i;
	//Deal with the head node here,and set the tail pointer
	Push(&head,1);
	tail=head;

	//Do all the other nodes using 'tail'
	for(i=2;i<6;i++)
	{
		Push(&(tail->next),i);
		tail=tail->next;
	}
	return head;	// head == {1, 2, 3, 4, 5};

}
struct node*BuildWithDummyNode()
{
	struct node dummy;
	struct node*tail=&dummy;

	int i;
	dummy.next=NULL;
	for(i=1;i<6;i++)
	{
		Push(&(tail->next),i);
		tail=tail->next;
	}
	return dummy.next;

}
struct node*BuildWithLocalRef()
{
	struct node*head=NULL;
	struct node**lastPtrRef=&head;//start out pointing to the head pointer
	for(int i=1;i<6;i++)
	{
		Push(lastPtrRef,i);
		lastPtrRef=&((*lastPtrRef)->next);
	}
	return head;// head == {1, 2, 3, 4, 5};
}
int main()
{
	//printf("%d",LengthTest());
	//print_list(BuildOneTwoThree());
	//print_list(PushTest());
	//print_list(BasicsCaller());

	//three method
	//struct node*head=AddAtHead();
	//struct node*head=BuildWithSpecialCase();
	//struct node*head=BuildWithDummyNode();

	//print_list(head);

}
//c++ virsions
#include<iostream>
using namespace std;

struct node{
	int data;
	node*next;
	node(int x) :data(x), next(nullptr){}
};
int Length(node*head)
{
	node*cur = head;
	int count = 0;
	while (cur != nullptr)
	{
		count++;
		cur = cur->next;
	}
	return count;
}
node*BuildOneTwoThree()
{
	node*One = new node(1);
	node*Two = new node(2);
	node*Three = new node(3);
	One->next = Two;
	Two->next = Three;
	Three->next = nullptr;
	return One;
}
void Push(node* &headRef, int elem)
{
	node*cur = new node(elem);
	cur->next = headRef;
	headRef = cur;
}
void Print(node*head)
{
	node*cur = head;
	while (cur != nullptr)
	{
		cout << cur->data<<" ";
		cur = cur->next;
	}
	cout << endl;
}
void BasicsCaller()
{
	node*head;
	int len;
	head = BuildOneTwoThree();
	Push(head, 13);
	Push(head->next, 42);
	//Print(head);
	len = Length(head);
}
//build at head with push()
node*AddAtHead()
{
	node*head = nullptr;
	for (int i = 1; i < 6; i++)
	{
		Push(head, i);
	}
	return head;
}
//Build With Tail Pointer
node*BuildWithSpecialCase(){
	node*head = nullptr;
	node*tail;
	int i;
	Push(head, 1);
	tail = head;
	for (i = 2; i < 6; i++)
	{
		Push(tail->next, i);
		tail = tail->next;//necessory
	}
	return head;
}
//Build by Dummy Node
node*BuildWithDummyNode(){
	node dummy(-1);
	node*tail = &dummy;
	dummy.next = nullptr;

	for (int i = 1; i < 6; i++)
	{
		Push(tail->next, i);
		tail = tail->next;
	}
	return dummy.next;

}
//Build by local References
node*BuildWithLocalRef()
{
	node*head = nullptr;
	node**tail = &head;

	for (int i = 1; i < 6; i++)
	{
		Push(*tail, i);
		tail = &((*tail)->next);
	}
	return head;
}
int main()
{
	node*aRef = nullptr, *bRef = nullptr, *cRef = nullptr, *dRef = nullptr;
	aRef = AddAtHead();
	bRef = BuildWithSpecialCase();
	cRef = BuildWithDummyNode();
	dRef = BuildWithLocalRef();
	Print(aRef);
	Print(bRef);
	Print(cRef);
	Print(dRef);
}
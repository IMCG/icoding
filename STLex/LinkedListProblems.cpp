/*another:xuesen
  Data:2013/12/13
  Linked List Problem
  Stanford paper
*/
#include<iostream>
#include<assert.h>
using namespace std;
struct node{
	int data;
	node*next;
	node(int x) :data(x), next(nullptr){}
};
void Push(node*&head, int data)
{
	node*cur = new node(data);
	cur->next = head;
	head = cur;
}
void Print(node*head)
{
	while (head != nullptr)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}
/*1.Given a list and an int,return times*/
int Count(node*head, int searchFor)
{
	node*cur = head;
	int num = 0;
	while (cur != nullptr)
	{
		if (cur->data == searchFor)
			num++;
		cur = cur->next;
	}
	return num;
}
/*2.Given a list and an index,return the data in the nth node of list*/
int GetNth(node*head, int index)
{
	//assert the index isvalid
	node*cur = head;
	int i = 0;
	//int count==index
	while (index > 0 && cur != nullptr)
	{
		cur = cur->next;
		index--;
	}		
	return cur->data;
}
/*3.make empty*/
void DeleteList(node* &head)
{
	node*cur = head;
	while (head->next != nullptr)
	{
		cur = head->next;
		delete head;
		head = cur;
	}
	head = nullptr;
}
/*How to delete list
1.next=current->next;
2.free(current);
3.current=next;
*/
/*4.the opposite of Push,take a non-empty list and remove front node*/
int Pop(node*& headRef)
{
	if (headRef == nullptr) return 0;
	int res;
	//protect the headRef
	node*cur = headRef;
	res = cur->data;
	headRef = cur->next;
	delete cur;
	return res;
}
/*5.A move general version of Push()*/
void InsertNth(node*&headRef, int index, int data)
{
	if (index == 0) Push(headRef, data);
	else {
		/*while (index > 1 && headRef != nullptr)
		{
			headRef = headRef->next;
			index--;
		}*/
		//the node cur is needed.
		node*cur = headRef;
		for (int i = 0; i < index - 1; i++)
		{
			assert(cur != nullptr);
			cur = cur->next;
		}
		assert(cur != nullptr);
		Push(cur->next, data);
	}
}
/*6.SortdInsert:SortedLIst and Insert a single node*/
void SortedInsert1(node*&headRef, node*newNode)
{
	int insert_num = newNode->data;
	if (headRef == nullptr || headRef->data >= insert_num){
		newNode->next = headRef;
		headRef = newNode;
	}
	else{
		node*cur = headRef;
		while (cur->next != nullptr && cur->next->data < insert_num)
		{
			cur = cur->next;
		}
		newNode->next = cur->next;
		cur->next = newNode;
	}
}
void SortedInsert2(node*&headRef, node*newNode)
{
	node dummy(-1);
	node*current = &dummy;
	dummy.next = headRef;

	while (current->next != nullptr && current->next->data < newNode->data)
		current = current->next;
	newNode->next = current->next;
	current->next = newNode;

	headRef = dummy.next;
}
/*7.InsertSort:can use SortedInsert*/
void InsertSort(node*&head)
{
	node*result = nullptr;
	node*cur = head;
	node*next;
	while (cur!= nullptr)
	{
		next = cur->next;
		SortedInsert1(result, cur);
		cur = next;
		/*SortedInsert(result, cur);
		cur = cur->next;
		worong!!!!*/
	}
	head = result;
}
int main()
{
	int A[6] = { 7, 5, 2, 9, 6, 4 };
	node*head = nullptr;
	for (int i = 5; i >= 0; i--)
	{
		Push(head, A[i]);
	}
	//7,5,2,9,6,4
	Print(head);
	InsertSort(head);
	Print(head);
}

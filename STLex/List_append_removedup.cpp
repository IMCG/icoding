/*author:xuesen
Data:2013/12/15
ListProblem{Append,Split
and RemoveDuplicates
}
*/
#include<iostream>
using namespace std;
struct node{
	int data;
	node*next;
	node(int x) :data(x), next(nullptr){}
};
void Push(node*&head, int elem)
{
	node*cur = new node(elem);
	cur->next = head;
	head = cur;
}
int length(node*head)
{
	int len=0;
	while (head != nullptr)
	{
		head = head->next;
		len++;
	}
	return len;
}
void SortedInsert(node*&head, node*newNode)
{
	node dummy(0);
	node*tail = &dummy;
	dummy.next = head;

	while (tail->next != nullptr && tail->next->data < newNode->data)
		tail = tail->next;
	newNode->next = tail->next;
	tail->next = newNode;
	head = dummy.next;
}
void InsertSort(node*&head)
{
	node*current = head;
	node*result = nullptr;
	node*next = nullptr;
	while (current != nullptr)
	{
		next = current->next;
		SortedInsert(result, current);
		current = next;
	}
	head = result;
}
void Print(node*head)
{
	while (head)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}
// Append 'b' onto the end of 'a', and then set 'b' to NULL.
void Append(node*&aRef, node*&bRef)
{
	node*cur = aRef;
	while (cur->next != nullptr)
		cur = cur->next;
	cur->next = bRef;
	bRef = nullptr;
}
//Split the nodes of the given list into front and back halves
void FrontBackSplit(node*sourse, node*&aRef, node*&bRef)
{
	node*current = sourse;
	int len = length(sourse);
	for (int i = 1; i < (len + 1) / 2; i++)
		current = current->next;
	bRef = current->next;
	current->next = nullptr;
	aRef = sourse;
}
//Split uses two pointers to tarverse the list
void FrontBackSplit1(node*sourse, node*&aRef, node*&bRef)
{
	node*slow = sourse;
	node*fast = sourse;
	while (fast != nullptr)
	{
		fast = fast->next;
		if (fast != nullptr){
			slow = slow->next;
			fast = fast->next;
		}
	}
	bRef = slow->next;
	slow->next = nullptr;
	aRef = sourse;
}
//Remove duplicates form a sorted list
void RemoveDuplicates1(node*head)
{
	node*current = head;
	if (current == nullptr)return;
	while (current->next != nullptr)
	{
		if (current->data == current->next->data)
		{
			node*next = current->next->next;
			delete current->next;
			current->next = next;
		}
		else{
			current = current->next;
		}
	}
}
//Take the node from the front of the source, and move it to
//the front of the dest.
void MoveNode(node*&destRef, node*&srcRef)
{
	node*current = srcRef;
	if (current == nullptr)return;

	srcRef = current->next;
	current->next = destRef;
	destRef = current;
}
void AlternatingSplit(node*sourse, node* &aRef, node* &bRef)
{
	node*current = sourse;
	while (current != nullptr)
	{
		MoveNode(aRef, current);
		if (current != nullptr)
			MoveNode(bRef,current);
	}
}
int main()
{
	int A[7] = { 5, 3, 8, 4, 9, 6, 2 };
	node*aRef = nullptr;
	for (int i = 6; i >= 0; i--)
		Push(aRef, A[i]);
	Print(aRef);
	int B[7] = { 3, 7, 4, 9, 5, 6, 5 };
	node*bRef = nullptr;
	for (int j = 6; j >= 0; j--)
		Push(bRef, B[j]);
	Print(bRef);
	node*a = nullptr, *b = nullptr;
	AlternatingSplit(aRef, a, b);
	Print(a);
	Print(b);
	return 0;	
}
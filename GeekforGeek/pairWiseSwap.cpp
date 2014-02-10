//Pairwise swap elements of a given linked list by changing links
#include<iostream>
using namespace std;
struct node
{
	int data;
	node*next;
	node(int x) :data(x), next(nullptr){}
};
void push(node*&head, int elem)
{
	node*cur = new node(elem);
	cur->next = head;
	head = cur;
}
void printList(node*head)
{
	while (head)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}
void pairWiseSwap1(node*head)
{
	node*temp = head;
	while (temp&&temp->next)
	{
		swap(temp->data, temp->next->data);
		temp = temp->next->next;
	}
}
void pairWiseSwap2(node*head)
{
	if (head && head->next)
	{
		swap(head->data, head->next->data);
		pairWiseSwap2(head->next->next);
	}
}
void pairWiseSwap3(node*&head)
{
	if (!head || !(head->next))
		return;
	//Initialize prev and cur pointers
	node*prev = head;
	node*curr = head->next;

	head = curr;//change head
	//travarse the list
	while (true)
	{
		node*next = curr->next;
		curr->next = prev;

		if (!next || !(next->next))
		{
			prev->next = next;
			break;
		}
		//change next of previous to next next
		prev->next = next->next;
		//update prev and curr
		prev = next;
		curr = prev->next;
	}
}
//recur
node *pairWiseSwap4(node*&head)
{
	//Base Case;
	if (!head || !(head->next))
		return head;
	//Store head of list after two nodes
	node*remaing = head->next->next;
	//change head
	node*newhead = head->next;
	//change next of second node
	head->next->next = head;
	//Recur for remaining list and change next of head
	head->next = pairWiseSwap4(remaing);

	return newhead;
}
int main()
{
	node*start = nullptr;
	push(start, 7);
	push(start, 6);
	push(start, 5);
	push(start, 4);
	push(start, 3);
	push(start, 2);
	push(start, 1);
	printList(start);

	//pairWiseSwap(start);

	//printList(start);

	pairWiseSwap1(start);

	printList(start);

	return 0;
}
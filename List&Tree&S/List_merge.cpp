//Merge a linked list into another linked list
//at alternate positions
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
void Print(node*head)
{
	node*temp = head;
	while (temp != nullptr)
	{
		cout << temp->data<<" ";
		temp = temp->next;
	}
	cout << endl;
}
void Merge(node*pRef, node*&qRef)
{
	node*p_cur = pRef;
	node*q_cur = qRef;
	node*p_next, *q_next;
	
	while (p_cur != nullptr && q_cur != nullptr)
	{
		p_next = p_cur->next;
		q_next = q_cur->next;
		//make a graph
		q_cur->next = p_next;
		p_cur->next = q_cur;

		p_cur = p_next;
		q_cur = q_next;
	}
	qRef = q_cur;
}
int main()
{
	node*p = nullptr, *q = nullptr;
	Push(p, 3);
	Push(p, 2);
	Push(p, 1);
	cout << "first linked list\n";
	Print(p);

	Push(q, 8);
	Push(q, 7);
	Push(q, 6);
	Push(q, 5);
	Push(q, 4);
	cout<<"Second Linked List:\n";
	Print(q);

	Merge(p, q);
	Print(p);
	Print(q);
	getchar();
	return 0;
}
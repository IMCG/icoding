/*TreeList.c*/
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
/*The node type from which both the tree and list are build*/
struct node{
	int data;
	struct node*small;
	struct node*large;
};
typedef struct node*Node;

/*helper function --given two list nodes,join them together so the
second immediately follow the first*/
static void join(Node a, Node b)
{
	a->large = b;
	b->small = a;
}
/*given two circular doubly linked lists.append them and return the new list*/
static Node append(Node a, Node b)
{
	Node alast, blast;
	if (a == nullptr)return b;
	if (b == nullptr)return a;

	//find the last node in each using the .previous pointer
	//在这里而不是产生了新的节点。
	alast = a->small;
	blast = b->small;

	//join the two tegether to make it connected anc circular
	join(alast, b);
	join(blast, a);

	return a;
}
/*Recursion--Given an binary tree,return a circular doubly linked list*/
static Node treeToList(Node root)
{
	Node alist, blist;
	if (root == nullptr)return nullptr;

	/*recursively solve subtrees  --leap of faith*/
	alist = treeToList(root->small);
	blist = treeToList(root->large);

	/*Make a length-1 list ouf of the root*/
	root->small = root;
	root->large = root;

	/*Append everything togeter in sorted order*/
	alist = append(alist, root);
	alist = append(alist, blist);

	return alist;
}
/*Create a new node*/
static Node newNode(int data)
{
	Node cur = new node;
	cur->data = data;
	cur->small = nullptr;
	cur->large = nullptr;
	return cur;
}
/*Add a new node into a tree*/
static void treeInsert(Node*rootRef, int data)
{
	Node root = *rootRef;
	if (root == nullptr)
		*rootRef = newNode(data);
	else
	{
		if (data <= root->data)
			treeInsert(&(root->small), data);
		else
			treeInsert(&(root->large), data);
	}
}
static void printList(Node head)
{
	Node current = head;
	while (current)
	{
		printf("%d ", current->data);
		current = current->large;
		//point
		if (current == head)break;
	}
	printf("\n");
}
/*Demo that the code works*/
int main()
{
	Node root = nullptr;
	Node head;
	treeInsert(&root, 4);
	treeInsert(&root, 2);
	treeInsert(&root, 1);
	treeInsert(&root, 3);
	treeInsert(&root, 5);

	head = treeToList(root);

	printList(head);	/*prints:1,2,3,4,5*/

	return 0;
}
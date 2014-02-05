#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*small;
	struct node*large;
};
typedef struct node*Node;

//helper function join them
static void Join(Node a,Node b){
	a->large=b;
	b->small=a;
}

//helper function append them
static Node append(Node a,Node b){
	Node aLast,bLast;
	if(a==NULL)return b;
	if(b==NULL)return a;

	aLast=a->small;
	bLast=b->small;

	Join(aLast,b);
	Join(bLast,a);

	return a;
}
//Recursion

static Node treeToList(Node root){
	Node aList,bList;
	if(root==NULL)return NULL;

	aList=treeToList(root->small);
	bList=treeToList(root->large);

	root->small=root;
	root->large=root;


	//Append everything together
	aList=append(aList,root);
	bList=append(bList,bList);

	return aList;
}
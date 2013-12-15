#include<iostream>
struct node{
	int data;
	node*left;
	node*right;
};
node* newNode(int data)
{
	node*cur=new node();
	cur->data=data;
	cur->right=nullptr;
	cur->left=nullptr;
	return (cur;
}
node* insert(node*head,int data)
{
	if(head==nullptr)return newNode(data);
	else{
		if(data<=head->data)
			head->left=insert(head->left,data);
		else
			head->right=insert(head->right,data);
	}
	return head;
}
// call newNode() three times
node* build123a()
{
	node*one=newNode(2);
	node*two=newNode(1);
	node*three=newNode(3);
	one->left=two;
	one->right=three;
	return one;
}
// call newNode() three times, and use only one local variable
node* build123b()
{
	node*one=newNode(2);
	one->left=newNode(1);
	one->right=newNode(3);
	return one;
}
/*
Build 123 by calling insert() three times.
Note that the '2' must be inserted first.
*/
node* build1232()
{
	node*root=nullptr;
	root=insert(root,2);
	root=insert(root,1);
	root=insert(root,3);
	return root;
}
int size(node*head)
{
	if(head==NULL)
		return 0;
	else
	    return size(head->left)+size(head->right)+1;
}
int maxDepth(node*head)
{
	if(head==NULL)return 0;
	else
	  return max(maxDepth(head->left),maxDepth(head->right))+1;
}
int minValue(node*head)
{
	node*current=head;
	while(current->left!=NULL)
	{
		current=current->left;
	}	
	return current->data;
}
void printArray(int ints[],int len)
{
	for(int i=0;i<len;i++)
	{
		cout<<ints[i];
	}
	cout<<endl;
}
void printPathRecur(node*head,int path[],int pathlen)
{
	if(head==NULL)return;
	path[pathlen]=head->data;
	pathlen++;
	if(head->left==NULL && head->right==NULL)
	{
		printArray(path,pathlen);
	}else{
		printPathRecur(head->left,path,pathlen);
		printPathRecur(head->right,path,pathlen);
	}
}
void printPaths(node*head)
{
	int path[1000];
	printPathRecur(head,path,0);	
}

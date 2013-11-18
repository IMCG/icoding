#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

const int maxn=100;
typedef struct Node{
	int data;
	Node *lchild,*rchild,*parent;
};
Node *head,*p,node[maxn];
int cnt;
void init()
{
	head=p=NULL;
	memset(node,'\0',sizeof(node));
	cnt=0;
}
void insert(Node *head,int x)
{
	if(head==NULL)
	{
		node[cnt].data=x;
		node[cnt].parent=p;
		head=&node[cnt++];
		return ;
	}
	p=head;
	if(x<head->data)
		insert(head->lchild,x);
	else
		insert(head->rchild,x);
}
int maxDepth(Node *head)
{
	if(head==NULL)
		return 0;
	return 1+max(maxDepth(head->lchild),maxDepth(head->rchild));
}
int minDepth(Node *head)
{
	if(head==NULL)
		return 0;
	return 1+min(minDepth(head->lchild),minDepth(head->rchild));
}
bool isBanlance(Node *head)
{
	return (maxDepth(head)-minDepth(head)<=1);
}
int main()
{
    init();
    int a[] = {
        2,1,3,4,5
    };
    for(int i=0; i<5; ++i)
        insert(head, a[i]);

	cout<<isBanlance(head)<<endl;
}
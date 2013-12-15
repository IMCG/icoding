#include<iostream>
using namespace std;
struct node{
	int data;
	node*left;
	node*right;
};
node*newNode(int data)
{
	node*cur = new node();
	cur->data = data;
	cur->left = NULL;
	cur->right = NULL;
	return cur;
}
node*Insert(node*head, int data)
{
	if (head == NULL)return newNode(data);
	else if (data <= head->data)
		head->left = Insert(head->left, data);
	else
		head->right = Insert(head->right, data);
	return head;
}
void PrintArray(int A[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << A[i] << "";
	}
	cout << endl;
}
void printCur(node*head, int A[], int len)
{
	if (head == NULL)return;
	else{
		A[len] = head->data;
		len++;
		if (head->left == NULL && head->right == NULL)
			PrintArray(A, len);
		else{
			printCur(head->left, A, len);
			printCur(head->right, A, len);
		}
	}
}
void PrintTree(node*head)
{
	int A[1000];
	printCur(head, A, 0);
}
int main()
{
	node*root = newNode(5);
	int T[6] = {3,8,1,4,7,9};
	for (int i = 0; i < 6; i++)
	{
		root = Insert(root,T[i]);
	}
	PrintTree(root);
}
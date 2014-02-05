#include<iostream>
using namespace std;
struct node{
	int data;
	node*left;
	node*right;
};
node*newNode(int data)
{
	node*current = new node();
	current->data = data;
	current->left = NULL;
	current->right = NULL;
	return current;
}
node*insert_node(node*head, int data)
{
	if (head == NULL)return newNode(data);
	else{
		if (data <= head->data)
			head->left = insert_node(head->left, data);
		else
			head->right = insert_node(head->right, data);
	}
	return head;
}
void mirror(node*head)
{
	if (head == NULL)return;
	if (head->left == NULL){
		head->left = head->right;
	}
	else if (head->right == NULL)
	{
		head->right = head->left;
	}
	else{
		node*current = head->left;
		head->left = head->right;
		head->right = current;
	}
	 mirror(head->left);
	 mirror(head->right);
}
void Print_or(node*head)
{
	if (head == NULL)return;
	Print_or(head->left);
	cout << head->data;
	Print_or(head->right);
}
int main()
{
	node*root = newNode(4);
	int A[4] = {
		2, 5, 1, 3
	};
	for (int i = 0; i<4; i++)
	{
		root = insert_node(root, A[i]);
	}
	cout << "prev....\n";
	Print_or(root);
	cout << "next....\n";
	mirror(root);
	Print_or(root);
	return 0;
}

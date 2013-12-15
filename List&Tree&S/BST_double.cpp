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
void Print_or(node*head)
{
	if (head == NULL)return;
	Print_or(head->left);
	cout << head->data;
	Print_or(head->right);
}
//change sort is ok
void doubleTree1(node*head)
{
	if (head == NULL)return;
	
	head->left = insert_node(head->left, head->data);
	
	doubleTree1(head->left->left);
	doubleTree1(head->right);

}
void doubleTree1(node*head)
{
	if (head == NULL)return;
	
	doubleTree1(head->left);
	doubleTree1(head->right);
	head->left = insert_node(head->left, head->data);
	
	

}
void doubleTree(node*head)
{
	node*oldleft;
	if (head == NULL)return;
	//do the subtrees
	doubleTree(head->left);
	doubleTree(head->right);

	oldleft = head->left;
	head->left = newNode(head->data);
	head->left->left = oldleft;
}
int main()
{
	node*root = NULL;
	int A[3] = {
		 2,1,3
	};
	for (int i = 0; i<3; i++)
	{
		root = insert_node(root, A[i]);
	}
	cout << " prev....\n";
	Print_or(root);
	cout << "\n next...\n";
	doubleTree(root);
	Print_or(root);
	return 0;
}

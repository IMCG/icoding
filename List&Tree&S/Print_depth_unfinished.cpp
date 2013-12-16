#include<iostream>
using namespace std;
struct node{
	int data;
	node*left;
	node*right;
	node(int x) :data(x), left(nullptr), right(nullptr){}
};
node*newNode(int elem)
{
	node*cur = new node(elem);
	cur->left = nullptr;
	cur->right = nullptr;
	return cur;
}
node*InsertNode(node*head, int elem)
{
	if (head == nullptr)return newNode(elem);
	if (elem < head->data)
		head->left = InsertNode(head->left, elem);
	else
		head->right = InsertNode(head->right, elem);
	return head;
}
int path[10];
int d = 0, num = 0;
void getDepth(node*head)
{
	if (head == nullptr)return;
	d++;
	if (head->right==nullptr && head->left == nullptr)
		path[num++] = d;
	else{
		getDepth(head->left);
		getDepth(head->right);
	}
}
int main()
{
	int A[7] = {5,3,8,1,4,7,6};
	node*head = nullptr;
	for (int i = 0; i < 7; i++)
		head = InsertNode(head, A[i]);
	getDepth(head);
	for (int j = 0; j < 4; j++)
		cout << path[j] << " ";
	return 0;
}
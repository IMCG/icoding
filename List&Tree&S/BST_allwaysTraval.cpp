#include<iostream>
#include<stack>
#include<queue>
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
	else if (elem < head->data)
		head->left = InsertNode(head->left, elem);
	else
		head->right = InsertNode(head->right, elem);
	return head;
}
//Recursion
void pre_order(node*head)
{
	if (head == nullptr)return;
	cout << head->data << " ";
	pre_order(head->left);
	pre_order(head->right);
}
void in_order(node*head)
{
	if (head == nullptr)return;
	in_order(head->left);
	cout << head->data << " ";
	in_order(head->right);
}
void post_order(node*head)
{
	if (head == nullptr)return;
	post_order(head->left);
	post_order(head->right);
	cout << head->data << " ";
}
//Stack
void pre_order_stack(node*head)
{
	if (head == nullptr)return;
	node*cur = head;
	stack<node*>st;
	st.push(cur);
	while (!st.empty())
	{
		node*tmp = st.top();
		st.pop();
		cout << tmp->data << " ";
		if (tmp->right)
			st.push(tmp->right);
		if (tmp->left)
			st.push(tmp->left);
	}

}
void in_order_stack(node*head)
{
	if (head == nullptr)return;
	node*cur = head;
	stack<node*>st;
	while (!st.empty() || cur != nullptr)
	{
		if (cur != nullptr)
		{
			st.push(cur);
			cur = cur->left;
		}
		else
		{
			cur = st.top();
			st.pop();
			cout << cur->data << " ";
			cur = cur->right;
		}
	}
}
void post_order_stack(node*head)
{
	node*cur = head;
	node*tag;
	stack<node*>st;

	do
	{
		while (cur != nullptr)
		{
			st.push(cur);
			cur = cur->left;
		}
		tag = nullptr;
		while (!st.empty())
		{
			cur = st.top();
			st.pop();
			//有孩子不存在或已被访问，访问之
			if (cur->right == tag)
			{
				cout << cur->data << " ";
				tag = cur;
			}
			else
			{
				//重新进栈
				st.push(cur);
				cur = cur->right;
				break;
			}
		}
	}while (!st.empty());
}
void level_order_stack(node*head)
{
	//respace the stack to queue
	if (head == nullptr)return;
	queue<node*>myq;
	node*cur = head;
	myq.push(cur);
	while (!myq.empty())
	{
		node*tmp = myq.front();
		myq.pop();
		cout << tmp->data << " ";
		if (tmp->left)
			myq.push(tmp->left);
		if (tmp->right)
			myq.push(tmp->right);
	}
}
int main()
{
	int A[8] = {5,3,8,1,4,7,9,6};
	node*head = nullptr;
	for (int i = 0; i < 8; i++)
		head = InsertNode(head, A[i]);
	cout << "pre_order\n";
	pre_order(head);
	cout << endl;
	pre_order_stack(head);
	cout << endl;

	cout << "in_order\n";
	in_order(head);
	cout << endl;
	in_order_stack(head);
	cout << endl;

	cout << "post_order\n";
	post_order(head);
	cout << endl;
	post_order_stack(head);
	cout << endl;

	cout << "level_order\n";
	level_order_stack(head);
	return 0;
}
#include<iostream>
#include<stack>
#include<vector>
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
node*Insert(node*head, int elem)
{
	if (head == nullptr)return newNode(elem);
	if (elem < head->data)
		head->left = Insert(head->left, elem);
	else
		head->right = Insert(head->right, elem);

	return head;
}
vector<int>  prevorder_ir(node*head)
{
	vector<int> result;
	stack<node*> current;

	if (head == nullptr)return result;
	current.push(head);

	while (!current.empty())
	{
		node*cur = current.top();
		current.pop();
		result.push_back(cur->data);
		while (true)
		{
			if (cur->left)
				result.push_back(cur->left->data);
			if (cur->right)
				current.push(cur->right);
			cur = cur->left;
			if (!cur)
				break;
		}
	}
	return result;
}
//2
vector<int> preorderTraversal(node *root) {
	// IMPORTANT: Please reset any member data you declared, as
	// the same Solution instance will be reused for each test case.
	vector<int> ret;
	if (root == NULL)return ret;
	stack<node*> st;
	st.push(root);
	node* ptr;
	while (st.size() != 0){
		ptr = st.top();
		st.pop();
		ret.push_back(ptr->data);
		if (ptr->right != NULL)st.push(ptr->right);
		if (ptr->left != NULL)st.push(ptr->left);
	}
	return ret;
}
void prevorder_re(node*head)
{
	if (head == nullptr)return;
	cout << head->data << " ";
	prevorder_re(head->left);
	prevorder_re(head->right);
}
void Print(vector<int> v)
{
	for (auto c : v)
		cout << c << "";
	cout << endl;
}
int main()
{
	int A[] = {5,3,8,1,4,7,9};
	node*root = nullptr;
	for (int i = 0; i < 7; i++)
		root = Insert(root, A[i]);

	cout << ".......................digui" << endl;
	prevorder_re(root);
	cout << endl;
	cout << ".......................diedai" << endl;
	vector<int> result=prevorder_ir(root);
	Print(result);
	return 0;
}
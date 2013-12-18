#include<iostream>
#include<algorithm>
#include<stack>
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
	cur->right = nullptr;
	cur->left = nullptr;
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
int minDepth1(node*head)
{
	if (head == nullptr)return 0;
	else
		return min(minDepth1(head->left), minDepth1(head->right)) + 1;
}
int minDepth2(node*head)
{
	if (head == nullptr)return 0;
	int result = INT_MAX;

	stack<pair<node*,int> > s;
	s.push(make_pair(head, 1));

	while (!s.empty()){
		auto cur = s.top().first;
		auto depth = s.top().second;
		s.pop();
		if (cur->left == nullptr && cur->right == nullptr)
			result = min(result, depth);
		if (cur->left && result > depth)//深度控制，剪枝
			s.push(make_pair(cur->left, depth + 1));
		if (cur->right&& result > depth)
			s.push(make_pair(cur->right, depth + 1));
	}
	return result;
}
int maxDepth1(node*head)
{
	if (head == nullptr)return 0;
	else
		return max(maxDepth1(head->left), maxDepth1(head->right)) + 1;
}
int maxDepth2(node*head)
{
	if (head == nullptr)return 0;
	int result = INT_MIN;

	stack<pair<node*, int> > s;
	s.push(make_pair(head, 1));

	while (!s.empty()){
		auto cur = s.top().first;
		auto depth = s.top().second;
		s.pop();
		if (cur->left == nullptr && cur->right == nullptr)
			result = max(result, depth);
		if (cur->left && result < depth)//深度控制，剪枝
			s.push(make_pair(cur->left, depth + 1));
		if (cur->right&& result < depth)
			s.push(make_pair(cur->right, depth + 1));
	}
	return result;
}
int main()
{
	int A[] = {5,3,8,1,4,7,9,10,11};
	node*head = nullptr;
	for (int i = 0; i < 9; i++)
		head = InsertNode(head, A[i]);
	/*int num = minDepth1(head);
	int num1 = minDepth2(head);
	cout << num << endl;
	cout << num1 << endl;*/
	cout << maxDepth1(head) << endl;
	cout << maxDepth2(head) << endl;
}
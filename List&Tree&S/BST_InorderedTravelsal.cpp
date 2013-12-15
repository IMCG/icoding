#include<iostream>
#include<vector>
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
	cur->left = nullptr;
	cur->right = nullptr;
	return cur;
}
node*Insert(node*head, int elem)
{
	if (head == nullptr)return newNode(elem);
	else if (elem < head->data)
		head->left = Insert(head->left, elem);
	else
		head->right = Insert(head->right, elem);
	return head;
}
//Thinking stack & Recuring ..
void InorderTraversal(node*head)
{
	if (head == nullptr)return;
	InorderTraversal(head->left);
	cout << head->data << " ";
	InorderTraversal(head->right);
}
//push the leftTree into stack then pop and push the rightTree into stack
vector<int> InorderTravel(node*head)
{
	vector<int>result;
	stack<node*>cur;
	node*p = head;
	if (head == nullptr)return result;
	while (!cur.empty() || p != nullptr)
	{
		if (p != nullptr)
		{
			cur.push(p);
			p = p->left;
		}
		else
		{
			p = cur.top();
			cur.pop();
			result.push_back(p->data);
			p = p->right;
		}
	}
	return result;
}
// MorrisInOrder()：
//  while 没有结束
//    如果当前节点没有左后代
//      访问该节点
//      转向右节点
//    否则
//      找到左后代的最右节点，且使最右节点的右指针指向当前节点
//      转向左后代节点
//Morris
vector<int> In_t(node*head)
{
	vector<int>result;
	//node*prev = nullptr;
	node*cur = head;
	while (cur != nullptr)
	{
		if (cur->left == nullptr)
		{
			result.push_back(cur->data);
			//prev = cur;
			cur = cur->right;
		}
		else
		{
			auto nod = cur->left;
			while (nod->right != nullptr && nod->right != cur)
				nod = nod->right;
			if (nod->right == nullptr){
				nod->right = cur;
				cur = cur->left;
			}
			else{
				result.push_back(cur->data);
				nod->right = nullptr;
				//prev = cur;
				cur = cur->right;
			}
		}
	}
	return result;
}
int main()
{
	int A[] = {5,3,8,1,4,7,9,6};
	node*head = nullptr;
	for (int i = 0; i < 8; i++)
		head = Insert(head, A[i]);
	vector<int> coll = InorderTravel(head);
	for (auto c : coll)
		cout << c << " ";
	cout << endl;
}
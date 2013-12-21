#include<iostream>
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
node*InsertNode(node*head, int elem)
{
	if (head == nullptr)return newNode(elem);
	else if (elem < head->data)
		head->left = InsertNode(head->left, elem);
	else
		head->right = InsertNode(head->right, elem);
	return head;
}
bool sumPath(node*head, int sum)
{
	if (head == nullptr)
		return false;
	else if (head->left == nullptr && head->right == nullptr)
		return sum == head->data;
	return sumPath(head->left, sum - head->data) || sumPath(head->right, sum - head->data);
}
//&的重要性
void pathSumcur(node*head, int gap, vector<int> &v,vector<vector<int> >&result)
{
	if (head == nullptr)return;
	v.push_back(head->data);
	if (head->left == nullptr&&head->right == nullptr)
	{
		if (head->data == gap)
			result.push_back(v);
	}
	pathSumcur(head->left, gap - head->data, v, result);
	pathSumcur(head->right, gap - head->data, v, result);

	v.pop_back();
}
vector<vector<int> > allSumPath(node*head, int sum)
{
	vector<vector<int> >result;
	vector<int>cur;
	pathSumcur(head, sum, cur, result);
	return result;
}
void PrintDvector(vector<vector<int> > result)
{
	for (size_t i = 0; i < result.size(); i++)
	{
		for (size_t j=0; j < result[i].size(); j++)
			cout << result[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}
void PrintArray(int A[], int len)
{
	for (auto i = 0; i < len; i++)
		cout << A[i] <<" ";
	cout << endl;
}
//递归的打印所有路径
void printPathRecur(node*head, int path[],int len)
{
	if (head == nullptr)return;
	path[len++] = head->data;

	if (head->left == nullptr && head->right == nullptr)
		PrintArray(path,len);
	else{
		printPathRecur(head->left, path,len);
		printPathRecur(head->right, path,len);
	}
}
void printPath(node*head)
{
	int path[100] = {};
	printPathRecur(head, path,0);
}
//打印所有叶子节点的深度
int num = 0;
void PrintDepth(node*head,int path[],int d)
{
	if (head == nullptr)return;
	d++;
	if (head->left == nullptr && head->right == nullptr)
		path[num++] = d;
	else{
		PrintDepth(head->left, path, d);
		PrintDepth(head->right, path, d);
	}
}
int main()
{
	int A[] = {5,3,8,1,4,7,9,6};
	node*head = nullptr;
	for (int i = 0; i < 8; i++)
		head = InsertNode(head, A[i]);
	//cout << sumPath(head, 20);
	//printPath(head);
	int path[10] = {};
	PrintDepth(head, path, 0);
	PrintArray(path, num);
	return 0;
}
/*把二元查找数转变为排序的双向链表
不能创建节点，只调整指针指向
    10
	/ \
  6		14
/	\  /   \
4	8 12	16
转换成双向链表4=6=8=10=12=14=16
*/
#include<iostream>
#include<stack>
using namespace std;
struct BSTreeNode
{
	int m_nValue;		//value of node
	BSTreeNode *m_Left;	//left
	BSTreeNode *m_Right;//right
	BSTreeNode(int x):m_nValue(x), m_Left(nullptr), m_Right(nullptr){}
};
BSTreeNode*NewNode(int elem)
{
	BSTreeNode*cur = new BSTreeNode(elem);
	cur->m_Left = nullptr;
	cur->m_Right = nullptr;
	return cur;
}
BSTreeNode*InsertNode(BSTreeNode*head, int elem)
{
	if (head == nullptr)return NewNode(elem);
	else if (elem < head->m_nValue)
		head->m_Left = InsertNode(head->m_Left, elem);
	else
		head->m_Right = InsertNode(head->m_Right, elem);
	return head;
}
void PrintTree(BSTreeNode*&head)
{
	if (head == nullptr)return;
	PrintTree(head->m_Left);
	cout << head->m_nValue << " ";
	PrintTree(head->m_Right);
}
void in_order_stack(BSTreeNode*head)
{
	if (head == nullptr)return;
	BSTreeNode*cur = head;
	stack<BSTreeNode*>st;
	while (!st.empty() || cur != nullptr)
	{
		if (cur != nullptr)
		{
			st.push(cur);
			cur = cur->m_Left;
		}
		else
		{
			cur = st.top();
			st.pop();
			cout << cur->m_nValue << " ";
			cur = cur->m_Right;
		}
	}
}
int num[7] = { 10, 6, 14, 4, 8, 12, 16 };
int main()
{
	BSTreeNode*head = nullptr;
	for (int i = 0; i < 7; i++)
	{
		head = InsertNode(head, num[i]);
	}
	//PrintTree(head);
	in_order_stack(head);
	return 0;
}
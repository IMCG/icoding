//最后谁剩下
#include<iostream>
using namespace std;

struct LinkNode
{
	LinkNode(int n) :Value(n){}
	int Value;
	LinkNode*next;
};
int main()
{
	int m, n, i;
	cout << "Please input n(nodes): ";
	cin >> n;
	cout << "Please input m: ";
	cin >> m;

	//create list
	LinkNode*head = new LinkNode(0);
	head->next = head;

	LinkNode*cur = head;
	for ( i = 0; i < n; i++)
	{
		LinkNode*tmp = new LinkNode(i);
		cur->next = tmp;
		tmp->next = head;
		cur = cur->next;    //总是指向最后一个
	}

	//play begin
	while (head!=head->next)
	{
		for (i = 1; i < m - 1;i++)
		{
			head = head->next;
		}
		head->next = head->next->next;//delete node
		head = head->next;
	}
	cout << head->Value << endl;
	return 0;
}
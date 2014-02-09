//Sort a linked list in O(n log n) time using constat space complexity.
//可以考虑用优先队列。vector<ListNode*>   <- ->error;
#include<iostream>
#include<queue>
#include<vector>
#include<assert.h>
using namespace std;
struct ListNode
{
	int val;
	ListNode*next;
	ListNode(int x) :val(x), next(nullptr){}
};
ListNode*Push(ListNode*&head, int elem)
{
	ListNode*cur = new ListNode(elem);
	cur->next = head;
	return cur;
}
void Print(ListNode*head)
{
	while (head)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}
class MyCompare{
public:
	bool operator()(ListNode*a, ListNode*b){
		return a->val > b->val;
	}
};
class Solution{
public:
	ListNode *sortlist(ListNode *head)
	{
		priority_queue<ListNode*,vector<ListNode*>,MyCompare> q;
		ListNode*tmp = head;
		while (tmp)
		{
			//tmp = head->next;
			q.push(tmp);
			tmp = tmp->next;
		}
		
		ListNode dummy(0), *cur = &dummy;
		ListNode*node = nullptr;
		while (!q.empty())
		{
			node = q.top();
			q.pop();
			cur=cur->next = node;
		}		
		return dummy.next;
	}
	ListNode *sortlist1(ListNode* head)
	{
		vector<ListNode*> coll;
		while (head)
		{
			coll.push_back(head);
			head = head->next;
		}
		sort(coll.begin(), coll.end(), MyCompare());
		ListNode dummy(0), *cur = &dummy;

		while (!coll.empty())
		{
			ListNode*node = coll.back();
			coll.pop_back();
			cur->next = node;
			cur = cur->next;
		}
		return dummy.next;
	}
};
int main()
{
	int a[] = { 3, 7, 4, 9, 5, 6, 5, 8, 6 };
	ListNode*head = nullptr;
	for (auto& i : a)
	{
		head = Push(head, i);
	}
	Print(head);
	ListNode*cur = nullptr;
	Solution s;
	cur = s.sortlist1(head);
	Print(head);
	return 0;
}
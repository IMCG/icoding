//复用mergetwo lists
ListNode *mergeKLists(vector<ListNode*> &lists)
{
	if (lists.size()==0)
		return nullptr;
	ListNode*p = lists[0];
	for (size_t i = 0; i < lists.size(); i++)
	{
		p = MergeTwoLists(lists[i], p);
	}
	return p;
}

//Solution: Find the smallest list-head first using minimum-heap(lgk).
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};
class Mycompare{
public:
	bool operator()(ListNode*a,ListNode*b)
	{
		return a->val > b->val;
	}
};
class Solution{
public:
	ListNode*mergeKLists(vector<ListNode*>&lists)
	{
		priority_queue<ListNode*, vector<ListNode*>, Mycompare>q;
		for (size_t i = 0; i < lists.size(); i++)
		{
			if (lists[i])
				q.push(lists[i]);
		}
		ListNode dummy(0), *cur = &dummy;
		while (!q.empty())
		{
			ListNode*node = q.top();
			q.pop();
			cur = cur->next = node;
			if (node->next)
				q.push(node->next);
		}
		return dummy.next;
	}
};     
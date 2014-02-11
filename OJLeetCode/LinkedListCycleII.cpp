#include<iostream>
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
/*
Input:	{1}, no cycle
Output:	tail connects to node index 0
Expected:	no cycle
*/
class Solution{
public:
	ListNode* detectCycle(ListNode*head)
	{
		if (head == nullptr)
			return head;
		//注意这里应该是head.而不是head->next;
		ListNode*fast = head;
		ListNode*slow = head;
		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow)
				break;
		}
		if (slow == fast)
		{
			fast = head;
			while (fast != slow)
			{
				fast = fast->next;
				slow = slow->next;
			}
			return fast;
		}
		else
			return nullptr;
		
	}
};
int main()
{
	ListNode*head = nullptr;
	ListNode*cycle = nullptr;
	//int a[] = { 3, 7, 4, 9, 5, 6, 8 };
	head = Push(head, 3);
	head = Push(head, 7);
	head = Push(head, 6);
	head = cycle = Push(head, 4);
	head = Push(head, 9);
	head = Push(head, 5);
	head = Push(head, 6);
	head = Push(head, 8);

	ListNode*cur = head;
	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = cycle;

	Solution s;
	ListNode*inode = s.detectCycle(head);
	cout << inode->val;
	//cout << boolalpha<< s.hasCycle(head);

	//Print(head);

	return 0;
}


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode*fast=head,*slow=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                ListNode*slow2=fast;
                while(slow2!=slow){
                    slow2=slow2->next;
                    slow=slow->next;
                }
                return slow2;
            }
        }
        return nullptr;
    }
};
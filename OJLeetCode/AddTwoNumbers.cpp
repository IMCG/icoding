//Add Two Numbers
/*You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain a single digit.
 Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/
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
class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode dummy(-1), *cur = &dummy;
		int carry = 0;
		//注意l1,l2;不应该是l1 = l1->next == nullptr ? nullptr : l1->next,
		//eg:{1,8}和{0}
		for (; l1 || l2;
			l1 = l1 == nullptr ? nullptr : l1->next,
			l2 = l2 == nullptr ? nullptr : l2->next,
			cur = cur->next)
		{
			const int val1 = l1 == nullptr ? 0 : l1->val;
			const int val2 = l2 == nullptr ? 0 : l2->val;
			int num = (val1 + val2 + carry) % 10;
			carry = (val1 + val2 + carry) / 10;
			//注意这个地方。new
			cur->next = new ListNode(num);
		}
		if (carry)
			cur->next = new ListNode(carry);

		return dummy.next;
	}
};
int main()
{
	ListNode*a = nullptr;
	a = Push(a, 8);
	a = Push(a, 1);
	Print(a);
	//a = Push(a, 2);
	ListNode*b = nullptr;
	b = Push(b, 0);
	//b = Push(b, 6);
	//b = Push(b, 5);
	Print(b);
	ListNode*c = nullptr;
	Solution s;
	c = s.addTwoNumbers(a, b);
	Print(c);
	cout << endl;
	return 0;
}
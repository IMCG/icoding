#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void push(ListNode*&head, int elem)
{
	ListNode*cur = new ListNode(elem);
	cur->next = head;
	head = cur;
}
void print(ListNode*head)
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
	ListNode *swapPairs(ListNode *head) {
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode*prev = head;
		ListNode*cur = head->next;
		head = cur;
		while (true){
			//there should be cur->next not next->next->next;
			ListNode*next = cur->next;
			cur->next = prev;
			//最后一定是爱这里返回。
			if (next == nullptr || next->next==nullptr){
				//不管怎样，都是prev->next=next;
				prev->next = next;
				break;
			}
			else
				prev->next = next->next;
			prev = next;
			cur = prev->next;
		}
		return head;
	}
};
int main()
{
	ListNode*head = nullptr;
	push(head, 6);
	push(head, 5);
	push(head, 4);
	push(head, 3);
	push(head, 2);
	push(head, 1);

	print(head);
	Solution s;
	head = s.swapPairs(head);
	print(head);
	return 0;
}
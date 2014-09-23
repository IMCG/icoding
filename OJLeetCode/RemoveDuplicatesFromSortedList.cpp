/*Date:2014/2/14
@Author:icodingc
update:2014/9/23
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void push(ListNode*&root, int elem)
{
	ListNode*cur = new ListNode(elem);
	cur->next = root;
	root = cur;
}
void print(ListNode*root)
{
	while (root)
	{
		cout << root->val << " ";
		root = root->next;
	}
	cout << endl;
}
/*考虑特殊情况[1,1,1]  [1,1,2]
*/
////AC  60ms
class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode*prev = head;
		ListNode*cur = head->next;
		ListNode*tmp = nullptr;
		while (cur)
		{
			if (prev->val == cur->val)
			{
				tmp = cur->next;
				prev->next = tmp;
				//free(cur);
				if (tmp == nullptr)
					break;
				cur= tmp;
			}
			else{
				cur = cur->next;
				prev = prev->next;
			}
		}
		return head;
	}
};
int main()
{
	ListNode*head = nullptr;
	//push(head, 3);
	//push(head, 3);
	push(head, 2);
	push(head, 1);
	push(head, 1);

	print(head);
	Solution s;
	head = s.deleteDuplicates(head);
	print(head);

	return 0;
};


//update 2014/9/23
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
////AC  84ms
//判断p->val和p->next->val是否相等即可。
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
    	//注意函数参数边界测试
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode* p = head;
        //ListNode* s = nullptr;
        while(p->next != nullptr){
            if(p->val == p->next->val){
                //s = p->next;
                p->next = p->next->next;
                //free(s);
            }else
                p=p->next;
        }
        return head;
    }
};
//AC  96ms
//把重复的数字往前替换 
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode* p = head;
        ListNode* q = head->next;
        ListNode* s = nullptr;
        while(q!=nullptr){
            if(p->val==q->val)
                q = q->next;
            else{
                p = p->next;
                p->val = q->val;
            }
        }
        //free q
        q = p->next;
        p->next = nullptr;
        
        while(q!=nullptr){
            s=q;
            q=q->next;
            free(s);
        }
        
        return head;
    }
};
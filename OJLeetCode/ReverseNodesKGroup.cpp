/*Given a linked list, reverse the nodes of a linked list k at a time and 
return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the 
end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head == nullptr || head->next == nullptr || k < 2)
            return head;
        ListNode *next_group = head;
        for(int i = 0;i < k;i++){
            if(next_group)
                next_group = next_gruop->next;
            else
                return head;
        }
        //next_group is the head of next group
        ListNode *new_next_group = reverseKGroup(next_group,k);
        ListNode *prev = nullptr,*cur = head;
        while(cur != next_group){
            ListNode *next = cur->next;
            cur->next=prev?prev:new_next_group;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};
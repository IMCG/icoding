//merge sorted list.array
ListNode * mergeTwoList(ListNode *l1, ListNode *l2) {
    ListNode *h = NULL;
    ListNode **p = &h;
    while(l1 && l2) {
        if(l1->val < l2->val){
            *p = l1;
            l1 = l1->next;
        }
        else {
            *p = l2;
            l2 = l2->next;
        }
        p = &((*p)->next);
    }
    if(l1) *p = l1;
    else *p = l2;
    return h;
}

// a recursive solution
class Solution {
public:
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (l1==NULL) return l2;
    if (l2==NULL) return l1;
    ListNode *ret;
    if (l1->val < l2->val) {
        ret = l1;
        ret->next = mergeTwoLists(l1->next,l2);
    }  else {
        ret = l2;
        ret->next = mergeTwoLists(l1,l2->next);
    }
    return ret;
}
};
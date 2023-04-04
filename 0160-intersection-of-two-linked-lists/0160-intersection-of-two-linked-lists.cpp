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
    //basically loop around until both dummy nodes meet , very easy question
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *a=headA,*b=headB;
        while(a&&b&&a!=b){
            a=a->next;
            b=b->next;
            if(a==b)return a;
            if(a==nullptr)a=headA;
            if(b==nullptr)b=headB;
        }
    return a;}
};
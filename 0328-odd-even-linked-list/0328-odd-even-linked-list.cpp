/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // ListNode *first=new ListNode();
        // ListNode *second=new ListNode();
        // ListNode*conn=second,*start=first;
        // ListNode* curr=head;
        // while(curr){
        //     if(curr->val%2==1){
        //         first->next=curr;
        //         first=first->next;
        //     }
        //     else {
        //         second->next=curr;
        //         second=second->next;
        //     }
        //     curr=curr->next;
        // }
        // second->next=NULL;
        // first->next=conn->next;
        // return start->next;
        if(!head||!head->next||!head->next->next)return head;
        ListNode*odd=head,*even=head->next;
        ListNode*evenhead=even;
        while(even&&even->next){
            odd->next=even->next;
            odd=even->next;
            even->next=odd->next;
            even=odd->next;
        }
        odd->next=evenhead;
        return head;
    }
};
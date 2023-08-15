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
    ListNode* partition(ListNode* head, int x) {
        // vector<int>less,grt;
        // ListNode*curr=head;
        // while(curr){
        //     if(curr->val<x)less.push_back(curr->val);
        //     else grt.push_back(curr->val);
        //     curr=curr->next;
        // }
//         turns out there's even more efficient way to do this 
        ListNode *first=new ListNode();
        ListNode *second=new ListNode();
        ListNode*conn=second,*start=first;
        ListNode* curr=head;
        while(curr){
            if(curr->val<x){
                first->next=curr;
                first=first->next;
            }
            else {
                second->next=curr;
                second=second->next;
            }
            curr=curr->next;
        }
        second->next=NULL;
        first->next=conn->next;
        return start->next;
    }
};
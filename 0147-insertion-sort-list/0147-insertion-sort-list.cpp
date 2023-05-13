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
//     how is this problem even medium
//     a nice problem, if u wanna brainfuck ur mind
//     ListNode* insertionSortList(ListNode* head) { // this was my intuitive solution but give TLE
//         ListNode* d=new ListNode(-1,head);
//         ListNode* curr=head->next,*prev=head;
//         while(curr){
//             while(curr->val>=prev->val){
//                 prev->next=curr;
//                 curr=curr->next;
//                 // continue;
//             }
//                 ListNode* temp=head;
//                 while(curr->val>temp->next->val)temp=temp->next;
//                 prev->next=curr->next;
//                 curr->next=temp->next;
//                 temp->next=curr;
//                 curr=prev->next;
            
//         }
//     return d->next;}
//     the below solution is technically bubble sort..lol but works in O(n2)-worst and O(n2)best
    ListNode* insertionSortList(ListNode* head){
        for(ListNode* curr=head;curr!=NULL;curr=curr->next){
            for(ListNode*j=head;j!=NULL;j=j->next){
                if(j->val>curr->val)swap(j->val,curr->val);
            }
        }
        return head;
    }
};
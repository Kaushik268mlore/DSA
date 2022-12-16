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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tail=head,*prev=NULL,*curr=head;
        int cnt=0;
        while(tail){
            tail=tail->next;
            cnt++;
        }
        if(cnt==n){
           return head->next;
        }
       tail =head;
        for(int i=0;i<cnt-n;i++){
          prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        
  return head;  }
};

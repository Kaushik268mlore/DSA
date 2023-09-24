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
    ListNode* getmid(ListNode*head){
        ListNode*slow=head,*fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reversal(ListNode*head){
        ListNode* prev=NULL,*curr=head,*temp=NULL;
        while(curr != NULL){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    bool comparelist(ListNode*head1,ListNode*head2){
        while(head1 && head2){
            if(head1->val!=head2->val)return false;
            head1=head1->next;
            head2=head2->next;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *h1=head,*h2,*mid;
        mid=getmid(head);
        h2=reversal(mid);
        return comparelist(h2,h1);
    }
};
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
    ListNode *detectCycle(ListNode *head) {//okay , this one is a cycle detection problem
        //again will solve it using the cycle detection algorithm
        ListNode *slow=head , *fast=head;
        for(slow,fast;fast&&fast->next;){slow=slow->next;fast=fast->next->next;if(slow==fast)break;}
        if(!(fast&&fast->next))return nullptr;
        while(head!=slow){
            head=head->next;
            slow=slow->next;
        }
        return head;
    }
};
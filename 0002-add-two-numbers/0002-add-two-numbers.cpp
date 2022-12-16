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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode *newNode=new ListNode(0);
        ListNode *t=newNode;
        while(carry||l1||l2){
            carry+=(l1?l1->val:0)+(l2?l2->val:0);
            t->next= new ListNode(carry%10);
            t=t->next;
            if(l2)l2=l2->next;
            if(l1)l1=l1->next;
            carry/=10;

        }
        return newNode->next;
    }
};
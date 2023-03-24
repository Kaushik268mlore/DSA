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
    // ListNode* mergeNodes(ListNode* head) { //holy shit i tried to create a new list , and that won't be a single pass solution 
    //     ListNode *main=head;
    //     ListNode*root=new ListNode();
    //     while()
    // }
    ListNode* mergeNodes(ListNode* head){
        ListNode* p=head;
        ListNode *res=new ListNode();
        ListNode*q=res;
        int sum=0;
        
        for(p=p->next;p;p=p->next){
            if(!p->val){
                q->next=new ListNode(sum);
                q=q->next;
                sum=0;
            }
            sum+=p->val;
        }
    return res->next;
    }
};
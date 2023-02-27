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
    ListNode* middleNode(ListNode* head) {
        //a very simple slow and fast pointer question
        ListNode*f=head,*sec=head;
        for(f,sec;f&&f->next;sec=sec->next,f=f->next->next){}
        return sec;
    }
};
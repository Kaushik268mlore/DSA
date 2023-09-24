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
// This looks like LIS in linkedlist
    ListNode* removeNodes(ListNode* head) {
        ListNode*curr=head;
        vector<int>s;
        while(curr){
            while(s.size()!=0&&s.back()<curr->val)s.pop_back();
            s.push_back(curr->val);
            curr=curr->next;
        }
        auto newnode=head;
        curr=head;
        for(auto ptr:s){
            newnode->val=ptr;
            curr=newnode;
            newnode=newnode->next;
        }
        curr->next=NULL;
        return head;
    }
};
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
    // i kinda had to refer an editorial
    ListNode* reverse(ListNode* start,ListNode*end){
        ListNode* cur = start->next;
        ListNode* new_head_prev = cur;
        ListNode* prev = start;
        ListNode* next;

        while(cur != end){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        start->next = prev;
        new_head_prev->next = cur;
        
        return new_head_prev;
    }
//     ListNode* reverseKGroup(ListNode* head, int k) {
//      
//     if (head == nullptr || head->next == nullptr) {
//         return head;
//     }
//     ListNode* preNode = nullptr;
//     ListNode* curNode = head; 
//     ListNode* nextNode = head->next;  
//     head = nextNode;
//     while (curNode != nullptr && nextNode != nullptr) {
//         curNode->next = nextNode->next;
//         nextNode->next = curNode;
//         if (preNode) {
//             preNode->next = nextNode;
//         }
//         preNode = curNode;
//         curNode = curNode->next;       
//         if (curNode) {
//             nextNode = curNode->next;
//         }
//     }
//     return head;

//     }
    ListNode* reverseKGroup(ListNode* head, int k){
        if(!head || !head->next || k == 1) return head;
        
        ListNode* dummy_head = new ListNode(-1);
        dummy_head->next = head;
        ListNode* group_head_prev = dummy_head;
        
        for(int i = 1; head; ++i){
            if(i%k == 0){
                group_head_prev = reverse(group_head_prev, head->next);
                head = group_head_prev->next;
            }else{
                head = head->next;
            }
        }
        
        return dummy_head->next;
    }
};
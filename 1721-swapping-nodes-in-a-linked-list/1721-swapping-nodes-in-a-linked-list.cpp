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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* root=head;
        vector<int>arr;
        for(root;root;arr.push_back(root->val),root=root->next){
            
        }
        int n=size(arr);
        swap(arr[k-1],arr[n-k]);
        int i;
        root=head;
        for(i=0;i<n;root=root->next,i++){
            root->val=arr[i];
        }
    return head;}
};
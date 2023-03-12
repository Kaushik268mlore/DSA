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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //a very intuitive divide and conquer solutiion much similar to the binary search approach.
    TreeNode *helper(ListNode* start,ListNode*end){//so this helper function finds the middle of the linked list which is supposed to be the root , as the list is already sorted
        if(start==end)return NULL;
        ListNode*slow=start,*fast=start;
        while(fast!=end&&fast->next!=end){
            slow=slow->next;
            fast=fast->next->next;
        }
        TreeNode *root=new TreeNode(slow->val);//we create a new Node in the BST using the mid value in the sub-segment of the linkedlist [start,end];
        root->left=helper(start,slow);
        root->right=helper(slow->next,end);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
       if(!head)return NULL;//this case handles if the root of the list is NULL
        if(!head->next){//this case handles if there is just one single node.
            TreeNode *root=new TreeNode(head->val);
            return root;
        }
        return helper(head,NULL);
    }
};
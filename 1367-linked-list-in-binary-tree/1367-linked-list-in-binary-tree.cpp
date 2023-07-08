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
    bool helper(TreeNode* root,ListNode* head){
        if(!head)return true; // we reached the end.
        if(!root)return false;
        return head->val==root->val&&(helper(root->left,head->next)||helper(root->right,head->next));
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!head)return true;
        if(!root)return false;
        return helper(root,head)||isSubPath(head,root->left)||isSubPath(head,root->right);
    }
};
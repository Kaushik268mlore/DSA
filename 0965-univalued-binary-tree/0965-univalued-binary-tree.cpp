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
    void helper(TreeNode* root,unordered_set<int>&s){
        s.insert(root->val);
        if(!root->right&&!root->left)return;
        if(root->right)helper(root->right,s);
        if(root->left)helper(root->left,s);
    }
    bool isUnivalTree(TreeNode* root) {
        unordered_set<int>s;
        helper(root,s);
        return s.size()==1;
    }
};
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
    vector<int>s;
    void helper(TreeNode*n){
        if(!n)return;
        s.push_back(n->val);
        helper(n->right);
        helper(n->left);
    }
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        if(root->right)helper(root->right);
        if(root->left)helper(root->left);
        return s.size()+1;
        
    }
};
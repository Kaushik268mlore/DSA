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
    void preorder(TreeNode*root,string &s){
        if(root->left)preorder(root->left,s);
        if(root->right)preorder(root->right,s);
        if(!root->left&&!root->right){
            s+=char(root->val);
            return;
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1,s2;
        preorder(root1,s1);
        preorder(root2,s2);
        return s1==s2;
    }
};
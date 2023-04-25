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
    void helper(TreeNode*root,vector<int>&res,unordered_set<int>&s,int h){
        if(!root)return;
        if(s.find(h)==s.end()){
            s.insert(h);
            res.push_back(root->val);
        }
        helper(root->right,res,s,h+1);
        helper(root->left,res,s,h+1);
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        unordered_set<int>s;
        helper(root,res,s,0);
        return res;
    }
};
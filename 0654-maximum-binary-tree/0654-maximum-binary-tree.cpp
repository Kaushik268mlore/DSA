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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {//loved this solution 
        vector<TreeNode*>stack;
        for(int &num:nums){
            TreeNode* cur=new TreeNode(num);
            while(!stack.empty() and stack.back()->val<num){
                cur->left=stack.back();
                stack.pop_back();
            }
            if(!stack.empty()){
                stack.back()->right=cur;
            }
            stack.push_back(cur);
        }
        return stack.front();
    }
};
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
class Solution {//nice problem
public:
    bool helper(TreeNode*Left,TreeNode*Right){
        if(!Left&&!Right)return true;
        else if(!Left||!Right)return false;
        
        if(Left->val!=Right->val)return false;
        return helper(Left->right,Right->left)&&helper(Left->left,Right->right);
    }
    
    bool isSymmetric(TreeNode* root) {
        TreeNode* L=root,*R=root;
        return helper(L->right,R->left);
        }
    
};
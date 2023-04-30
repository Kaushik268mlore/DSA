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
    // recursive
    // TreeNode* invertTree(TreeNode* root) {
    //     if(root){
    //         invertTree(root->left);
    //         invertTree(root->right);
    //         swap(root->left,root->right);
    //     }
    // return root;}
    //iterative using stack
    TreeNode *invertTree(TreeNode* root){
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode* temp=st.top();
            st.pop();
            if(temp){
                st.push(temp->left);
                st.push(temp->right);
                swap(temp->left,temp->right);
            }
        }
    return root;}
};
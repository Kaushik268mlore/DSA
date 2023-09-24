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
   /* vector<int> inorderTraversal(TreeNode* root) {//normal recursive solution
        vector<int>res;
        inorder(root,res);
        return res;
    }
    void inorder(TreeNode* root,vector<int>&res){
        if(root!=NULL){
            inorder(root->left,res);
            res.push_back(root->val);
            inorder(root->right,res);
        }
    }*/
    //iterative solution using stack
    vector<int> inorderTraversal(TreeNode* root){
        vector<int>res;
        TreeNode* curr=root;
        stack<TreeNode*>st;
        while(curr!=NULL or !st.empty()){
            while(curr!=NULL){
                st.push(curr);
               curr=curr->left; 
            }
            curr=st.top();
            st.pop();
            res.push_back(curr->val);
            curr=curr->right;
        }
        return res;
    }
};
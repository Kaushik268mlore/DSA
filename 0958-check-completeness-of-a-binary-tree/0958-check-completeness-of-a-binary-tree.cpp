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
    //okay so a complete binary tree is something which has child in all nodes except the last level,
    // and in the last level  the nodes are can have any number of nodes considering that singular nodes HAVE TO BE FAR LEFT.
    int countNODES(TreeNode*root){
        if(!root)return 0;
        return countNODES(root->left)+countNODES(root->right)+1;
    }
    bool dfs(TreeNode*root,int ind,int n){
        if(!root)return true;
        if(ind>=n)return false;
        return dfs(root->left,2*ind+1,n)&&dfs(root->right,2*ind+2,n);
    }
    bool isCompleteTree(TreeNode* root) {
        return dfs(root,0,countNODES(root));
    }
};
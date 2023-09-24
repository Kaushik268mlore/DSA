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
    TreeNode* bstFromPreorder(vector<int>& preorder) {//recursive stack,visualise for better understanding.
        int i=0;
        return build(preorder,i,INT_MAX);
    }
    TreeNode* build(vector<int>&a,int &i,int bound ){
        if(i==a.size()||a[i]>bound)return NULL;
        TreeNode*root=new TreeNode(a[i++]);
        root->left=build(a,i,root->val);
        root->right=build(a,i,bound);
        return root;
    }
};
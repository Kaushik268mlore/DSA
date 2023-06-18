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
    bool check(TreeNode*n1,TreeNode*n2){
        if(n1==nullptr||n2==nullptr)return n1==nullptr&&n2==nullptr;
        bool res=n1->val==n2->val&&check(n1->left,n2->left)&&check(n1->right,n2->right);
        return res;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr)return false;
        if(check(root,subRoot))return true;
        return isSubtree(root->right,subRoot)||isSubtree(root->left,subRoot);
    }
};
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
   
    int dfs(TreeNode*node,int &length){
        // if(!node||node->val!=node->left->val||node->right->val!=node->val)return length;
        // if(node->right->val==node->val)dfs(node->right,length);
        // else if(node->left->val==node->val)dfs(node->right,length++);
        // return max(dfs(node->right,length),dfs(node->left,length));
        int l,r;
        if(node->left)l=dfs(node->left,length);
        else l=0;
        if(node->right)r=dfs(node->right,length);
        else r=0;
        if(node->left&&node->left->val==node->val)l++;
        else l=0;
        if(node->right&&node->right->val==node->val)r++;
        else r=0;
        length=max(l+r,length);
        return max(l,r);
    }
    //searching and maintaining a max length of the path till we get new values should do 
    int longestUnivaluePath(TreeNode* root) {
        int res=0;
        if(!root)return 0;
        dfs(root,res);
        return res;
    }
};
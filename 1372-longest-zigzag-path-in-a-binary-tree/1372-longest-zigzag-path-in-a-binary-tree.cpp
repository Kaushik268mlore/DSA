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
    // idk maybe go alternatively through all the paths and record the highest length, so definitely need a bfs 
    int res=0;
    void dfs(TreeNode*root,int length,bool flag){
        if(!root)return;
        res=max(length,res);
        if(flag){
            dfs(root->left,length+1,false);
            dfs(root->right,1,true);//you'll also be cghecking the right node from that point.
        }
        else {
        dfs(root->left,1,false);
        dfs(root->right,length+1,true);
        }
    }
    
    int longestZigZag(TreeNode* root) {
    dfs(root,0,false);
    dfs(root,0,true);
    return res;
    }
};
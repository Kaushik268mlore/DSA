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
    // simple bfs
    // even using dfs it can be done but by maintaining the current level
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root)return res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>dummy;
            int sz=q.size();
            while(sz--){
                TreeNode*d=q.front();
                dummy.push_back(q.front()->val);
                // if(q.front()->left)q.push(q.front()-left);
                // if(q.front()->right)q.push(q.front()-right);
                q.pop();
                if(d->left)q.push(d->left);
                if(d->right)q.push(d->right);
            }
            res.push_back(dummy);
            
        }
    return res;}
};
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
    
//     level order traversal.. problem aka bfs
    int maxLevelSum(TreeNode* root) {
        int ans=0;
        int level=0;
        int maxim=root->val;
        queue<TreeNode*>q;
        if(root->left)q.push(root->left);
        if(root->right)q.push(root->right);
        while(!q.empty()){
            int sum=0;
            level++;
            int n=q.size();
            for(int i=0;i<n;i++){
                auto node=q.front();
                sum+=node->val;
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            if(sum>maxim){
                maxim=sum;
                ans=level;
            }
        }
    return ans+1;}
};
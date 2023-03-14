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
    // void helper(TreeNode* root,vector<vector<int>>&res,vector<int>&aux){ //my failed solution
    //     if(root->left==NULL&&root->right==NULL){
    //         res.push_back(aux);
    //     }
    //     aux.push_back(root->val);
    //     if(root->right!=NULL)
    //         helper(root->right,res,aux);
    //     aux.pop_back();
    //     if(root->left!=NULL)
    //         helper(root->left,res,aux);
    // }
    // int num(vector<int>arr){
    //     int n=size(arr);
    //     int prod=0;
    //     for(int i=0,j=n;i<n,j>=1;i++,j--){
    //         prod+=(arr[i]*pow(10,j-1));
    //     }
    // return prod;}
    // int sumNumbers(TreeNode* root) {
    //     vector<vector<int>>res;
    //     vector<int>aux;
    //     helper(root,res,aux);
    //     int ans=0;
    //     for(int i=0;i<res.size();i++){
    //         ans+=(num(res[i]));
    //         cout<<num(res[i])<<" ";
    //     }
    // return ans;}
    int helper(TreeNode  * root,int value){
        if(!root)return 0;//base case
        value=value*10+root->val;//decimal number system.
        if(!root->left&&!root->right)return value;//if we have reached the end node, we return the value calculated till there.
        int leftSubTreeSUM=helper(root->left,value);
        int rightSubTreeSUM=helper(root->right,value);
        return leftSubTreeSUM+rightSubTreeSUM;
        
    }
    int sumNumbers(TreeNode* root){
        return helper(root,0);
    }
};
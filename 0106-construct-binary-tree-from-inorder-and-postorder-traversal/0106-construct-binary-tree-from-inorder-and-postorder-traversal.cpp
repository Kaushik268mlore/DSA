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
    int k;
    TreeNode* getTree(vector<int>& inorder, vector<int>& postorder,int i,int j) {
        if(i>j)
            return NULL;
        if(i==j)
            return new TreeNode(postorder[k--]);
        TreeNode* root=new TreeNode(postorder[k]);
        int index=find(inorder.begin()+i,inorder.begin()+j+1,postorder[k--])-inorder.begin();
        root->right=getTree(inorder,postorder,index+1,j);
        root->left=getTree(inorder,postorder,i,index-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        k=postorder.size()-1;
        return getTree(inorder,postorder,0,inorder.size()-1);
    }
};
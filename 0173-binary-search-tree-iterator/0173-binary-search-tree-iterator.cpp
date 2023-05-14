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
class BSTIterator {
public:
    TreeNode* node;
    vector<int>traversal;
    int t=0;
    BSTIterator(TreeNode* root) {
        node=root;
        traverse(root);
    }
    void traverse(TreeNode*root){
        if(root->left)traverse(root->left);
        traversal.push_back(root->val);
        if(root->right)traverse(root->right);
    }
    int next() {
        return traversal[t++];
    }
    
    bool hasNext() {
        return (t<traversal.size());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
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
    int preIdx = 0;
    int inIdx = 0;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return builder(preorder,inorder,INT_MAX);
    }

    TreeNode* builder(vector<int>& preorder, vector<int>& inorder,int limit){
        if(preIdx > preorder.size()-1){return nullptr;}
        if(inorder[inIdx] == limit){
            inIdx++;
            return nullptr;}
        TreeNode* root = new TreeNode(preorder[preIdx++]);
        root->left = builder(preorder,inorder,root->val);
        root->right = builder(preorder,inorder,limit);
        return root;
    }
};

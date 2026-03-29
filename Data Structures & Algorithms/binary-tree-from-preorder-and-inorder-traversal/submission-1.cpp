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
    unordered_map<int,int> treeMap;
    int preIndex = 0;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i<inorder.size(); i++){
            treeMap[inorder[i]] = i;
        }
        return builder(preorder,0,inorder.size()-1);
    }

    TreeNode* builder(vector<int>& preorder,int l,int r){
        if(l>r){return nullptr;}
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);
        int mIndex = treeMap[rootVal];
        root->left = builder(preorder,l,mIndex-1);
        root->right = builder(preorder,mIndex+1,r);
        return root;
    }
};

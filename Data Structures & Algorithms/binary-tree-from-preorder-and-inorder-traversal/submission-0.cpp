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
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i<inorder.size();i++){
            treeMap[inorder[i]] = i;
        }
        return builder(preorder,0,preorder.size()-1,0,inorder.size()-1);
    }
    TreeNode* builder(vector<int>& preorder, int pStart, int pEnd, int iStart, int iEnd){
        if(pStart>pEnd || iStart>iEnd){return nullptr;}
        int rootVal = preorder[pStart];
        TreeNode* root = new TreeNode(rootVal);
        int k = treeMap[rootVal];
        int leftSize = k - iStart;
        root->left = builder(preorder,pStart+1,pStart + leftSize,iStart,k - 1);
        root->right = builder(preorder,pStart+leftSize+1,pEnd,k + 1,iEnd);
        return root;
    }
};

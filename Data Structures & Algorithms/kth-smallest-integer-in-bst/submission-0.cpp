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
    int res;
    int count;
public:
    int kthSmallest(TreeNode* root, int k) {
        count = k;
        countBST(root);
        return res;
        
    }
    
    void countBST(TreeNode* root){
        if(!root){return;}
        countBST(root->left);
        count--;
        if(count == 0){
            res = root->val;
            return;
        }
        if(count>0){//剪枝，不然会继续执行完
            countBST(root->right);
        }
        
    }

    
};

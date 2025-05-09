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

    void invertRoot(TreeNode* root){
        if(root == NULL) return;
        
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        invertRoot(root->left);
        invertRoot(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        
        if(root == NULL) return root;
        else {
            invertRoot(root);
        }

        return root;
    }
};
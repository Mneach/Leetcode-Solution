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
    
    int currentValue = 0;
    
    void dfs(TreeNode* root){
        if(root){
            dfs(root->right);
            currentValue += root->val;
            root->val = currentValue;
            
            dfs(root->left);
        }
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        dfs(root);
        
        return root;
    }
};
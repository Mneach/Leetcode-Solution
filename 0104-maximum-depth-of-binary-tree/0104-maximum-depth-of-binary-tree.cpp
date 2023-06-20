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
    
    int dfs(TreeNode* root){
        if(root != NULL){
            int maxLeft = dfs(root->left);
            int maxRight = dfs(root->right);
            return max(maxLeft, maxRight) + 1;
        }else{
            return 0;
        }
    }
    
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }
};
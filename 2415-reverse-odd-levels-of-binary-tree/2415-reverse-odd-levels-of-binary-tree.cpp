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
    
    void dfs(TreeNode* leftTree, TreeNode* rightTree, int currDepth){
        if(leftTree && rightTree){
            if(currDepth % 2 == 0) swap(leftTree->val, rightTree->val);
            dfs(leftTree->left, rightTree->right, currDepth + 1);
            dfs(leftTree->right, rightTree->left, currDepth + 1);
        }
    } 
    TreeNode* reverseOddLevels(TreeNode* root) {
       dfs(root->left, root->right, 0);
        
        return root;
    }
};
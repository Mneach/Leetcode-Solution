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
    
    bool answer = true;
    
    int dfs(TreeNode* root){
        if(root){
            int leftHeight = dfs(root->left) + 1;
            int rightHeight = dfs(root->right) + 1;
            
            int diff = abs(leftHeight - rightHeight);
            
            if(diff > 1){
                answer = false;
            }
            
            return max(leftHeight, rightHeight);
        }
        
        return 0;
    }
    
    bool isBalanced(TreeNode* root) {
        
        dfs(root);
        
        return answer;
    }
};
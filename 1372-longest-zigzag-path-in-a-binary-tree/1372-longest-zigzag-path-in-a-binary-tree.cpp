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
    
    int dfs(TreeNode* root, int depth, bool moveLeft){
        
        if(root){
            int currDepthLeft, currDepthRight;
            
            if(moveLeft){
                currDepthLeft = dfs(root->left, 0, true);
                currDepthRight = dfs(root->right, depth + 1, false);
            }else{
                currDepthLeft = dfs(root->left, depth + 1,  true);
                currDepthRight = dfs(root->right, 0, false);
            }    
            
            depth = max(depth, max(currDepthLeft, currDepthRight));
        }
        return depth;
    }
    
    int longestZigZag(TreeNode* root) {
        
        if(!root) return 0;
        
        int leftDepth = dfs(root->left, 0, true);
        int rightDepth = dfs(root->right, 0, false);
        
        return max(leftDepth, rightDepth);
    }
};
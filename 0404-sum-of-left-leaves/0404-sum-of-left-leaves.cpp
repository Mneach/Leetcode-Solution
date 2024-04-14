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
    
    int answer = 0;
    
    void dfs(TreeNode* root, string move){
        if(root){
            dfs(root->left , "left");
            if(root->left == NULL && root->right == NULL && move == "left") answer += root->val;
            dfs(root->right, "right");
        }
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root, "");
        
        return answer;
    }
};
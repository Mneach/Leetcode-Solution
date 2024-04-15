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
    
    void dfs(int depth, TreeNode* root, int current){
        if(root){
            current = (current * 10) + root->val;
            dfs(depth + 1, root->left, current);
            dfs(depth + 1, root->right, current);
            
            if(!root->left && !root->right){
                answer += current;
            }
        }
    }
    
    int sumNumbers(TreeNode* root) {
        
        dfs(0, root, 0);
        
        return answer;
    }
};
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
    
    void dfs(TreeNode* root){
        if(root->left){
            dfs(root->left);
            
            if(root->val % 2 == 0){
                if(root->left->left) answer += root->left->left->val;
                if(root->left->right) answer += root->left->right->val;
            }

        }
        
        if(root->right){
            dfs(root->right);

            if(root->val % 2 == 0){
                if(root->right->right) answer += root->right->right->val;
                if(root->right->left) answer += root->right->left->val;               
            }
        }
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root);
        
        return answer;
    }
};
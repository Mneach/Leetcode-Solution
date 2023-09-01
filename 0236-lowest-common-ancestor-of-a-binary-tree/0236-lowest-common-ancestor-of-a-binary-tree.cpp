/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root->val == p->val || root->val == q->val) return root;
        
        if(!root->left && !root->right) return NULL;
        
        TreeNode* left = NULL;
        TreeNode* right = NULL;
        
        if(root->left) left = dfs(root->left, p, q);
        if(root->right) right = dfs(root->right, p, q);
        
        if(left && right) return root;
        else if(left) return left;
        else if(right) return right;
        else return NULL;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       TreeNode* answer;
        
       answer = dfs(root, p, q);
        
       return answer;
    }
};
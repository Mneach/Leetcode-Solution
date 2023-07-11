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
    
    int answer = 100001;
    void dfs(TreeNode* root, int currDepth){
        if(root){
            dfs(root->left, currDepth + 1);
            dfs(root->right, currDepth + 1);
            
            if(root->left == NULL && root->right == NULL){
                answer = min(answer, currDepth);
            }
        }
    } 
    
    int minDepth(TreeNode* root) {
       if(root == NULL) return 0;
       
       dfs(root, 0);
        
       return answer + 1;
    }
};
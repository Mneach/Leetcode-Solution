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
    
    void dfs(vector<int> &answer, TreeNode* root){
        if(root){
            
            dfs(answer, root->left);
            dfs(answer, root->right);
            
            if(root->left && root->right == NULL){
                answer.push_back(root->left->val);
            }
            
            if(root->left == NULL && root->right){
                answer.push_back(root->right->val);
            }
        }
    }
    
    vector<int> getLonelyNodes(TreeNode* root) {
       vector<int> answer; 
        
        dfs(answer, root);
        
        return answer;
    }
};
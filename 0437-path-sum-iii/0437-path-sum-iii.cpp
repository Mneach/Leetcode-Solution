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
    
    void countPath(TreeNode* root, int targetSum, long long int currentValue, int &answer){
       if(root){
          currentValue += root->val;
           
          if(currentValue == targetSum) answer++;
          
           countPath(root->left, targetSum, currentValue, answer);
           countPath(root->right, targetSum, currentValue, answer);
       } 
    }
   
    void dfs(TreeNode* root, int targetSum, int &answer){
        if(root){
            countPath(root, targetSum, 0, answer);
            dfs(root->left, targetSum, answer);
            dfs(root->right, targetSum, answer);
        }
    } 
    
    int pathSum(TreeNode* root, int targetSum) {
        int answer = 0;
        
        dfs(root, targetSum, answer);
        
        return answer;
    }
};
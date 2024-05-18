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
    
    int dfs(TreeNode* root, int& distance){
        if(root){
            
            int currentValue = root -> val;
            int rootRightValue = dfs(root -> right, distance);
            int rootLeftValue = dfs(root -> left, distance);
            
            currentValue += rootRightValue + rootLeftValue;
            root -> val = currentValue;
            
            distance += abs(rootRightValue) + abs(rootLeftValue);
            return currentValue - 1;
        }
        
        return 0;
    }
    
    int distributeCoins(TreeNode* root) {
        int distance = 0;
        dfs(root, distance);
        return distance;
    }
};
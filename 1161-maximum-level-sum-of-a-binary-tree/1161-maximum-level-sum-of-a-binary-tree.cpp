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
    
    void bfs(TreeNode* root, int depth, unordered_map<int,int> &um){
        if(root){
            um[depth] += root->val;
            bfs(root->left, depth + 1, um);
            bfs(root->right, depth + 1, um);
        }
    }
    
    int maxLevelSum(TreeNode* root) {
        
        if(!root) return 0;
        
        unordered_map<int,int> um;
        
        bfs(root, 1, um);
        
        int answer = -1;
        int maximumLevel = INT_MIN;
        
        for(auto data : um){
            if(maximumLevel <= data.second){
                maximumLevel = data.second;
                answer = data.first;
            }
        }
        
        return answer;
    }
};
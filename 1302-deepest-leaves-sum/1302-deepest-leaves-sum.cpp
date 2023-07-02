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
    
    int maxDepth = 0;
    int answer = 0;
    
    void recursive(TreeNode* root, int currDepth){
        if(root){
            recursive(root->left , currDepth + 1);
            recursive(root->right, currDepth + 1);
            
            if(currDepth == maxDepth){
                answer += root->val;
            }else if(currDepth > maxDepth){
                maxDepth = currDepth;
                answer = root->val;
            }
        }
    }
    
    int deepestLeavesSum(TreeNode* root) {
        recursive(root, 0);
        
        return answer;
    }
};
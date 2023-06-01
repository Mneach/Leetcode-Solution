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
    
    TreeNode* answer(TreeNode* original,TreeNode* cloned,TreeNode* target){
        if(original == NULL || cloned == NULL){
            return NULL;
        }else if(original == target){
            return cloned;
        }
        
        TreeNode *x = answer(original->left, cloned->left, target);
        
        if(x) return x;
        else return answer(original->right, cloned->right, target);
        
    }  
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        return answer(original, cloned, target);
    }
};
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
    
    void recursive(TreeNode* root, vector<int> &arr){
      if(root){
        recursive(root->left, arr);
        if(!root->right && !root->left) arr.push_back(root->val);
        recursive(root->right, arr);
      }
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> rootValues1;
        vector<int> rootValues2;
        
        recursive(root1, rootValues1);
        recursive(root2, rootValues2);
        
        return rootValues1 == rootValues2;
    }
};
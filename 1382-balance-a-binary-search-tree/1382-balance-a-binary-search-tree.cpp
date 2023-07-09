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
    
    void inOrder(TreeNode* root, vector<TreeNode*>& arr){
       if(root){
           inOrder(root->left, arr);
           arr.push_back(root);
           inOrder(root->right, arr);
       } 
    }
    
    TreeNode* constructBalanceTree(int start, int end, vector<TreeNode*>& arr){
        if(start > end) return NULL;
        
        int mid = (start + end) / 2;
        TreeNode* root = arr[mid];
        
        root->left = constructBalanceTree(start, mid - 1, arr);
        root->right = constructBalanceTree(mid + 1, end, arr);
        
        return root;
    } 
    
    TreeNode* balanceBST(TreeNode* root) {
        
        if(root == NULL) return NULL;
        
        vector<TreeNode*> arr;
        inOrder(root, arr);
        root = constructBalanceTree(0 , arr.size() - 1, arr); 
        return root;
    }
};
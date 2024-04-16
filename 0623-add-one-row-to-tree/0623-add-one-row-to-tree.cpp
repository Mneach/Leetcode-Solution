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
    
    void dfs(TreeNode* root, int val, int depth, int currentDepth){
        if(root){
            if(currentDepth + 1 == depth){
                TreeNode* newLeftNode = new TreeNode(val);
                TreeNode* newRightNode = new TreeNode(val);
                
                TreeNode* nextLeft = NULL;
                TreeNode* nextRight = NULL;
                
                nextLeft = root->left;
                newLeftNode->left = nextLeft;
                root->left = newLeftNode;
                
                nextRight = root->right;
                newRightNode->right = nextRight;
                root->right = newRightNode;
            }
            
            dfs(root->left, val, depth, currentDepth + 1);
            dfs(root->right, val, depth, currentDepth + 1);
            return;
        }
        
        
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(root == NULL) return root;
        
        if(depth == 1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            newRoot->right = NULL;

            root = newRoot;
        }else{
            dfs(root, val, depth, 1);           
        }
        
        return root;
    }
};
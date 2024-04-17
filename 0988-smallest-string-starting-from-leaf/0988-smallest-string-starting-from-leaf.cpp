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

    string answer = "";
    
    void dfs(TreeNode* root, string current){
        if(root){
            
            current = (char) (root->val + 'a') + current;
            
            if(root->left == NULL && root->right == NULL && (answer > current || answer == "")){
                answer = current;
            }
            
            if(root->left) dfs(root->left, current);
            if(root->right) dfs(root->right, current);
        }
    }
    
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return answer;
    }
};
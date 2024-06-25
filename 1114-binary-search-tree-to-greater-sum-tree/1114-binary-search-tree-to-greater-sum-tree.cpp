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

    int temp = 0;

    void dfs(TreeNode* root){
        if(root){
            dfs(root->right);
            int res = root->val + temp;
            temp += root->val;
            root->val = res;

            dfs(root->left);   
                 
        }
    }

    TreeNode* bstToGst(TreeNode* root) {
        dfs(root);

        return root;
    }
};
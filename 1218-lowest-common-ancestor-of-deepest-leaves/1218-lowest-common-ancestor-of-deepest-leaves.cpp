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

    pair<TreeNode*, int> dfs(TreeNode* root) {
        if (root == NULL) {
            return {NULL, 0}; 
        }

        auto leftNode = dfs(root -> left);
        auto rightNode = dfs(root -> right);

        if (leftNode.second > rightNode.second) {
            return {leftNode.first, leftNode.second + 1};
        } else if (leftNode.second < rightNode.second) {
            return {rightNode.first, rightNode.second + 1};
        }

        return {root, leftNode.second + 1};
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }
};
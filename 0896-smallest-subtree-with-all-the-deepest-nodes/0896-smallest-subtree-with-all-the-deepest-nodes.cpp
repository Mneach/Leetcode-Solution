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
            return {root, 0};
        }

        auto leftNode = dfs(root -> left);
        auto rightNode = dfs(root -> right);

        int leftScore = leftNode.second;
        int rightScore = rightNode.second;

        if (leftScore > rightScore) {
            return {leftNode.first, leftScore + 1};
        } else if (rightScore > leftScore) {
            return {rightNode.first, rightScore + 1};
        }

        return {root, leftScore + 1};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
       return dfs(root).first; 
    }
};
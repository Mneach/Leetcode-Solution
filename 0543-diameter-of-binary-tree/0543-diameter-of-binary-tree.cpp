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
private:

    int result = 0;

    int dfs(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int leftResult = dfs(root -> left);
        int rightResult = dfs(root -> right);
        result = max(result, leftResult + rightResult);

        return max(leftResult, rightResult) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);

        return result;
    }
};
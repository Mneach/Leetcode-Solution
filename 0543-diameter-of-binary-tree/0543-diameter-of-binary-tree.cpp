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
        } else if (root -> left == NULL && root -> right == NULL) {
            return 0;
        }

        int leftResult = dfs(root -> left);
        int rightResult = dfs(root -> right);

        // calculate the current result
        int currentResult = leftResult + rightResult;

        if (root -> left) {
            currentResult += 1;
        }

        if (root -> right) {
            currentResult += 1;
        }

        result = max(result, currentResult);

        return max(leftResult, rightResult) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);

        return result;
    }
};
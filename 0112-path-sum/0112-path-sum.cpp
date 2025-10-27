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

    bool dfs(TreeNode* root, int targetSum, int sum) {
        if (root == NULL) {
            return false;
        } else if (root -> left == NULL && root -> right == NULL) {
            if (targetSum == sum + root -> val) {
                return true;
            }

            return false;
        }

        bool leftResult = dfs(root -> left, targetSum, sum + root -> val);
        bool rightResult = dfs(root -> right, targetSum, sum + root -> val);

        return leftResult || rightResult;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum, 0);
    }
};
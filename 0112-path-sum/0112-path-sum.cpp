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
    
    bool dfs(TreeNode* root, int targetSum, int sum) {
        if (root) {
            if (root -> left == NULL && root -> right == NULL) {
                return sum + root -> val == targetSum;
            }
            bool left = dfs(root -> left, targetSum, sum + root -> val);
            bool right = dfs(root -> right, targetSum, sum + root -> val);

            return left || right;
        }

        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum, 0);
    }
};
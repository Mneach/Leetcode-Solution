/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int total = 0;
    TreeNode* result;

    int dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return 0;
        }

        int resultLeft = dfs(root -> left, p, q);
        int resultRight = dfs(root -> right, p , q);

        if (result != NULL) {
            return 0;
        } else if (resultLeft + resultRight == 2) {
            result = root;
        }

        if (root -> val == p -> val || root -> val == q -> val) {

            if (resultLeft == 1 || resultRight == 1) {
                result = root;
            }

            return 1;
        } else {
            return max(resultLeft, resultRight);
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);

        return result;
    }
};
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
    int calculateHeight(TreeNode* root, bool &result) {
        if (root == NULL) {
            return 0;
        }

        int leftHeight = calculateHeight(root -> left, result);
        int rightHeight = calculateHeight(root -> right, result);

        if (abs(leftHeight - rightHeight) > 1) {
            result = false;
        }

        return max(leftHeight, rightHeight) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
       bool result = true;
       calculateHeight(root, result);

       return result;
    }
};
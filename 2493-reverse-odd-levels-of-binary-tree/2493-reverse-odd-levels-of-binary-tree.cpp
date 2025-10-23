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
    void postOrderTraversal(TreeNode* leftRoot, TreeNode* rightRoot, int level) {
        if (leftRoot == NULL && rightRoot == NULL) {
            return;
        }

        postOrderTraversal(leftRoot -> left, rightRoot -> right, level + 1);
        postOrderTraversal(leftRoot -> right, rightRoot -> left, level + 1);

        if (level % 2 == 1) {
            swap(leftRoot -> val, rightRoot -> val);
        }
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (root == NULL) {
            return root;
        }

        postOrderTraversal(root -> left, root -> right, 1);

        return root;
    }
};
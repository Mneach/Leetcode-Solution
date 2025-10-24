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

    bool checkIdentical(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL && subRoot != NULL) {
            return false;
        } else if (root != NULL && subRoot == NULL) {
            return false;
        } else if (root == NULL && subRoot == NULL) {
            return true;
        }

        if (root -> val != subRoot -> val) {
            return false;
        }

        bool leftResult = checkIdentical(root -> left, subRoot -> left);
        bool rightResult = checkIdentical(root -> right, subRoot -> right);

        return leftResult && rightResult;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL && subRoot != NULL) {
            return false;
        } else if (root != NULL && subRoot == NULL) {
            return false;
        } else if (root == NULL && subRoot == NULL) {
            return true;
        }

        if (root -> val == subRoot -> val) {
            bool result = checkIdentical(root, subRoot);

            if (result) {
                return true;
            }
        }

        bool leftResult = isSubtree(root -> left, subRoot);
        bool rightResult = isSubtree(root -> right, subRoot);

        return leftResult || rightResult;
    }
};
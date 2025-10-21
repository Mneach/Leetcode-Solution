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
    void preOrderTransversal(string &result, TreeNode* root) {
        if (root == NULL) {
            return;
        }

        result += to_string(root -> val);

        if (root -> left == NULL && root -> right == NULL) {
            return;
        }

        result += '(';
        preOrderTransversal(result, root -> left);
        result += ')';

        if (root -> right != NULL) {
            result += '(';
            preOrderTransversal(result, root -> right);
            result += ')';
        }
    }
public:
    string tree2str(TreeNode* root) {

        if (root == NULL) {
            return "";
        }

        string result = "";
        preOrderTransversal(result, root);

        return result;
    }
};
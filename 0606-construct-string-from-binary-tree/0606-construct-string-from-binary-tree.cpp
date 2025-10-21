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
    void preOrderTranversal(string &result, TreeNode* root) {
        if (root == NULL) {
            return;
        }

        result += '(';
        result += to_string(root -> val);

        TreeNode* leftChild = root -> left;
        TreeNode* rightChild = root -> right;

        if (leftChild == NULL && rightChild != NULL) {
            result += "()";
            preOrderTranversal(result, root -> right);
        } else if (leftChild != NULL && rightChild == NULL) {
            preOrderTranversal(result, root -> left);
        } else {
            preOrderTranversal(result, root -> left);
            preOrderTranversal(result, root -> right);
        }

        result += ')';
    }
public:
    string tree2str(TreeNode* root) {

        if (root == NULL) {
            return "";
        }

        string result = "";
        result += to_string(root -> val);

        if (root -> left == NULL && root -> right != NULL) {
            result += "()";
            preOrderTranversal(result, root -> right);
        } else {
            preOrderTranversal(result, root -> left);
            preOrderTranversal(result, root -> right);
        }
        
        return result;
    }
};
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
    int index = 0;
    int dash = 0;
    int extractNumber(string traversal) {
        string result = "";
        while (index < traversal.length() && traversal[index] != '-') {
            result += traversal[index];
            index++;
        }
        return stoi(result);
    }

public:
    void dfs(TreeNode* root, string &traversal, int level) {
       while(index < traversal.length() && traversal[index] == '-') {
            dash++;
            index++;
       }

       if (dash == level) {
            // extract number
            int number = extractNumber(traversal);
            dash = 0;
            root -> left = new TreeNode(number);
            dfs(root -> left, traversal, level + 1);

            if (dash != level) return;

            number = extractNumber(traversal);
            dash = 0;
            root -> right = new TreeNode(number);
            dfs(root -> right, traversal, level + 1);
       }
    }

    TreeNode* recoverFromPreorder(string traversal) {
        int number = extractNumber(traversal);
        TreeNode* root = new TreeNode(number);

        dfs(root, traversal, 1);

        return root;
    }
};
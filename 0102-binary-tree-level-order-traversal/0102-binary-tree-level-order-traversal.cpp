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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> results;
        queue<TreeNode*> q;

        if (root == NULL) {
            return results;
        }

        q.push(root);
        
        while (q.empty() == false) {
            vector<int> result;
            int size = q.size();

            for (int i = 1; i <= size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node -> left) {
                    q.push(node -> left);
                } 

                if (node -> right) {
                    q.push(node -> right);
                }

                result.push_back(node -> val);
            }

            results.push_back(result);
        }

        return results;
    }
};
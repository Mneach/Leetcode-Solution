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
    vector<int> largestValues(TreeNode* root) {
        if (root == NULL) return {};

        vector<int> answer;
        queue<TreeNode*> q;
        q.push(root);

        while (q.size() > 0) {
            int size = q.size();

            int maximumValue = INT_MIN;
            for (int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();

                maximumValue = max(maximumValue, node -> val);

                if (node -> left) q.push(node -> left);
                if (node -> right) q.push(node -> right);
            }

            answer.push_back(maximumValue);
        }

        return answer;
    }
};







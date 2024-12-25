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
        int currentLevel = 0;

        // root -> val, level
        queue<pair<TreeNode*,int>> q;
        q.push({root, currentLevel + 1});

        int maximum = 0;
        while (q.size() > 0) {
            auto [node, level] = q.front();
            q.pop();

            if (currentLevel != level) {
                if(currentLevel != 0) answer.push_back(maximum);
                currentLevel = level;
                maximum = node -> val;                                
            } else {
                maximum = max(maximum, node -> val);
            }

            if (node -> left) q.push({node -> left, level + 1});
            if (node -> right) q.push({node -> right, level + 1});
        }

        answer.push_back(maximum);
    
        return answer;
    }
};







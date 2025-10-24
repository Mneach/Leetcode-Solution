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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        deque<TreeNode*> dq;
        vector<vector<int>> results;
        int level = 0;

        if (root != NULL) {
            dq.push_back(root);
        }

        while (dq.size() > 0) {
            vector<int> result;
            int levelSize = dq.size();

            for (int i = 0; i < levelSize; i++) {
                TreeNode* currentNode;
                if (level % 2 == 0) {
                    currentNode = dq.front();
                    dq.pop_front();

                    if (currentNode -> left) {
                        dq.push_back(currentNode -> left);
                    }
                
                    if (currentNode -> right) {
                        dq.push_back(currentNode -> right);
                    }
                } else {
                    currentNode = dq.back();
                    dq.pop_back();

                    if (currentNode -> right) {
                        dq.push_front(currentNode -> right);
                    }
                
                    if (currentNode -> left) {
                        dq.push_front(currentNode -> left);
                    }
                }



                result.push_back(currentNode -> val);
            }

            results.push_back(result);
            level += 1;
        }

        return results;
    }
};
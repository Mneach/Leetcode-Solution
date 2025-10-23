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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        int totalOperation = 0;

        if (root == NULL) {
            return totalOperation;
        }

        q.push(root);
        while (q.empty() == false) {
            vector<int> childValues;
            unordered_map<int,int> bucket;
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* currentNode = q.front();
                q.pop();

                if (currentNode -> left) {
                    childValues.push_back(currentNode -> left -> val);
                    bucket[currentNode -> left -> val] = childValues.size() - 1;
                    q.push(currentNode -> left);
                }

                if (currentNode -> right) {
                    childValues.push_back(currentNode -> right -> val);
                    bucket[currentNode -> right -> val] = childValues.size() - 1;
                    q.push(currentNode -> right);
                }
            }

            vector<int> sortedChildValues = childValues;
            sort(sortedChildValues.begin(), sortedChildValues.end());

            for (int i = 0; i < childValues.size(); i++) {

                if (childValues[i] != sortedChildValues[i]) {

                    totalOperation += 1;

                    int correctIndex = bucket[sortedChildValues[i]];
                    // update the index in the bucket
                    bucket[childValues[i]] = correctIndex;
                    
                    // swap the value
                    swap(childValues[i], childValues[correctIndex]);
                }
            }
        }

        return totalOperation;
    }
};
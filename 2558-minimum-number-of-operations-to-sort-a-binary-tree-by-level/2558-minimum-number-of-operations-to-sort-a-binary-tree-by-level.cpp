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
        q.push(root);

        int answer = 0;

        while (q.size() > 0){
            int totalNode = q.size();
            vector<int> idx(totalNode, 0);
            // fill with inc value
            iota(idx.begin(), idx.end(), 0);

            vector<int> arr(totalNode, 0); 

            for (int i = 0; i < totalNode; i++) {
                auto node = q.front();
                q.pop();

                arr[i] = node -> val;
                if (node -> left) q.push(node -> left);
                if (node -> right) q.push(node -> right);
            }

            // sort the index
            sort (idx.begin(), idx.end(), [&](int left, int right){
                return arr[left] < arr[right];
            });

            // compare
            for (int i = 0; i < totalNode;) {
                int j = idx[i];

                if (j != i) {
                    answer++;
                    swap(idx[i], idx[j]);
                } else {
                    i++;
                }
            }
        }
        return answer;
    }
};
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

/*

# Observation
1.	We need to traverse the tree level by level

# BFS (Queue)

# Simulation

    3
   / \
  9  20
     /\
    15 7


queue = 

resultPerLevel = [15,7]

results = [[3],[9,20],[15,7]]

# Pseudocode
1.	initialize variable
   - queue<TreeNode*> q
   - vector<vector<int>> results
2. if root == NULL, return results
3. push root into the queue
4. while queue is not empty
   - vector<int> result
   - get the queue size
   - loop from index 1 until size
     - get the node from the queue
     - pop the node from the queue
     - if the node has left child, push the left child into the queue
     - if the node has right child, push the right child into the queue
     - push the node into the result
   - push result into results array
5. return the results array

Time Complexity : O(N)
N -> total nodes in the tree

Memory Complexity : O(P)
P -> maximum total node at level x

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
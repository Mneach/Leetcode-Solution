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
1.	We need to return the most right node at every level in binary tree

# BFS (Queue)

# Main Idea
⦁	loop for every node at level x in the binary tree
⦁	get the most right node at level x

# Simulation

      1
     / \
    2   3
   /     \ 
  10      4
  /\
 20 30


Queue = 
Queue size = 2

i = 3
current node = 30

result
level 1 = 1
level 2 = 3
level 3 = 4
level 4 = 30


expected answer = [1,3,4,30]


# Pseudocode
1.	initialize variables
   - queue<Node*> q
   - vector<int> results
2. push the root into the queue
3. while queue is not empty
   - current result = 0
   - get the current queue size
     - current queue size = total node at that level
   - loop from 1 until current queue size (inclusive)
     - current data = get the data from the queue
     - pop the data from the queue
     - if the current node have a child, push the child into the queue
     - update the current result = current data 
   - push the current result into the results array
4. return the results array

Time Complexity : O(N)
N -> total nodes in the tree

Memory Complexity : O(P)
P -> total nodes at level x

*/

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> results;

        if (root == NULL) {
            return results;
        }

        q.push(root);

        while (q.empty() == false) {
            int currentResult = 0;
            int size = q.size();

            // visit all of the nodes at the current level
            for (int i = 1; i <= size; i++) {
                TreeNode* currentNode = q.front();
                q.pop();

                if (currentNode -> left) {
                    q.push(currentNode -> left);
                }

                if (currentNode -> right) {
                    q.push(currentNode -> right);
                }

                currentResult = currentNode -> val;
            }

            results.push_back(currentResult);
        }

        return results;
    }
};
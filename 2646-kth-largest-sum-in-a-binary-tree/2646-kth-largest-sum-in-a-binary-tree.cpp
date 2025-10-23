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
⦁	We need to return k-th largest sum in the tree
⦁	We need to sum all of the nodes in the tree (level by level)
 - we can use BFS to traverse the node level by level
⦁	If the sum data < k, then return -1
⦁	Note that two nodes are on the same level if they have the same distance from the root.
⦁	we should use long long to save sum values

# BFS (Queue)

# Main Idea
⦁	Traverse the node level by level
⦁	For every level we need to sum the node val
⦁	we can push sum value to the priority queue
⦁	later we can look at into the priority queue to get the answer

# Simulation

       5
     /  \
    8    9
   /\    /\
  2  1  3  7
 /\
4  6

Level 0
=============
Queue = 8,9
current node = 5

Sum = 5
Prioirty Queue (max-heap) = 5


Level 1
==========
Queue = 2,1,3,7

current node = 9

sum = 8 + 9 = 17
Priority Queue (max-heap) = 17, 5

level 2
==========

Queue = | 4,6

current node = 7

sum = 13
Priority Queue (max-heap) = 17, 13, 5

level 3
==========
Queue = 

current node = 6

sum = 10
Priority Queue (max-heap) = 17, 13, 10, 5

find k-th largest element
k = 2

Priority Queue (max-heap) = 17, 13, 10, 5
result = 13

# Pseudocode
1.	initialize variables
   - queue<TreeNode*> q
   - priority_queue<long long> pq
2. if root == NULL, return 0
3. push root into the queue
4. while queue is not empty
   - size = q.size()
   - long long sum = 0
   - loop from index 0 until q.size()
     - currentNode = q.front()
     - pop the data from the queue
     - if the current node has left child
       - push left child into the queue
     - if the current node has right child
       - push right child into the queue
     - sum += currentNode -> val
   - push sum into the priority queue
5. result = get the k-th largest sum from the priority queue
6. return the result

Time complexity : O(N + log H + K)
N -> total nodes in the binary tree
H -> height of the binary tree

Memory Complexity : (log H)
H -> height of the binary tree


*/
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;        
        priority_queue<long long> pq;

        if (root == NULL) {
            return 0;
        }

        q.push(root);
        while(q.size() > 0) {
            long long sum = 0;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* currentNode = q.front();
                q.pop();

                if (currentNode -> left) {
                    q.push(currentNode -> left);
                }

                if (currentNode -> right) {
                    q.push(currentNode -> right);
                }

                sum += currentNode -> val;
            }

            pq.push(sum);
        }

        long long result = -1;
        while(k > 0 && pq.size() > 0) {
            long long currentData = pq.top();
            pq.pop();
            k--;

            if (k == 0) {
                result = currentData;
            }
        }

        return result;
    }
};
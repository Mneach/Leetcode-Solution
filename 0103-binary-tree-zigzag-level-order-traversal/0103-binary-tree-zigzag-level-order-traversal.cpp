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
1.	We are given the root in the binary tree, our task is to return the zigzag level order traversal of it's nodes values
   - even level, should be start from left to right
   - odd level, should be start from right to left


# BFS (Dequeu)

# Simulation

          3
         / \
        9  20
           /\
          15 7

level 0
===========
Dequeu = 3 | 9,20

current node = 3

current result = [3]
results = [[3]]

level 1
===========
Dequeu =  | 15,7

current node = 9

current result = [20,9]

results = [[3],[20,9]]

level 2
=================
Dequeu =  |

current node = 

current result = [15,7]

results = [[3],[20,9],[15,7]]

# Pseudocode
1.	initialize variables
   - deque<TreeNode*> q
   - level = 0
   - vector<vector<int>> results
2. push root into the deque
3. while deque is not empty
   - vector<int> result;
   - get size of current level
     - levelSize = deque.size()
   - loop from index 0 until levelSize
     - TreeNode* curretNode 
     - if level % 2 == 0
       - currentNode = q.front()
       - q.pop_front()
       - using push back to push the child into the deque
     - else    
       - currentNode = q.back()
       - q.pop_back()
       - using push front to push the child into the deque
     - push currentNode -> value into the result array
   - push result array into the results
   - add level by 1
4. return the results

Time Complexity : O(N)
N -> total nodes in the binary tree

Memory Complexity : O(M + N)
M -> total nodes at the level x in the binary tree
N -> total nodes in the binary tree

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
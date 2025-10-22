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
1.	We need to find the maximum depth of binary tree
   - maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
2. to get the max depth we can compare the height of left subtree and right subtree
3. We will use post order traversal to compute height of left subtree and right subtree

# DFS (post order traversal)

# Simulation

       3
      / \
     9  20
        / \
       15  7

-> height(9) = 1

-> height(15) = 1
-> height(7) = 1

-> height(20) = max(height(15), height(7)) = max(1,1) = 1
-> height(20) = 1 + 1 = 2

-> height(3) = max(height(9), height(20)) = max(1, 2) = 2
-> height(3) = 2 + 1 = 3

# Pseudocode
1.	create dfs functions with return int
   - if (root == NULL)
     - return 0
   - visit left child 
     - call dfs (root -> left) -> will return height of left child
   - visit right child
     - call dfs (root -> right) -> will return height of right child
   - return 1 + max(leftChildHeight,rightChildHeight)

Time Complexity : O(N)
N -> total node in the binary tree

Memory Complexity : O(H)
H -> height of binary tree

*/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int leftChildHeight = maxDepth(root -> left);
        int rightChildHeight = maxDepth(root -> right);

        return 1 + max(leftChildHeight, rightChildHeight);
    }
};
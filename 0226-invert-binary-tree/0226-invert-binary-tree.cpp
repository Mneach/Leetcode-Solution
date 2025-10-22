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
1.	We need to visit the child first, so we will use post order traversal to traverse the tree
   - visit left child
   - visit right child
   - swap left and right child
   - return root

# DFS (post order traversal)

# Simulation

     4
   /  \
  2    7
 / \   /\
3   1 9  6

# Pseudocode
1.	create invertTree function
   - if root == NULL, return root
   - visit left child
   - visit right chlid
   - swap the current left child with current right child
   - return root

Time Complexity : O(N)
N -> total node in the binary tree

Memory Complexity : O(H)
H -> height of binary tree

*/


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return root;
        }

        TreeNode* leftChild = invertTree(root -> left);
        TreeNode* rightChild = invertTree(root -> right);

        root -> left = rightChild;
        root -> right = leftChild;

        return root;
    }
};
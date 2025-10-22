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
1.	We need to insert the node into the binary search tree, we also need to follow BST rules
   - if current node == NULL, create a new node with the value that we want to insert 
   - else if the current node value < inserted value, move into the right child
   - else if the current node value > inserted value, move into the left child
2. It is guaranteed that the new value does not exist in the original BST.

# DFS

# Simulation

value = -100

      4
    /   \
   2     7
  / \   /
 1   3 6
/
-100

Time Complexity : O(N)
N -> total nodes in the binary tree

Memory Complexity : O(H)
H -> max height of the binary tree

*/

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            TreeNode* newNode = new TreeNode(val);
            return newNode;
        } else if (root -> val < val) {
            root -> right = insertIntoBST(root -> right, val);
        } else if (root -> val > val) {
            root -> left = insertIntoBST(root -> left, val);
        }

        return root;
    }
};
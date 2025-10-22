/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*

# Observation
1.	We need to find LCA from the binary search tree
   - The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants
2. If the current node is not p or q, we just need to return null, the reason is because of the current node should be our answer
3. if the current node is p, then we need to return p, the reason is because of the current node might be our answer
4. if the current node is q, then we need to return q, the reason is because of the current node might be our answer
5. if left child != NULL && right child != NULL, then return the current node
6. Need to check the child first before the parent
   - we can use post order traversal


# DFS (post order traversal)

# Simulation
p = 2
q = 5
               
               6
             /   \
            2     8
           / \    /\
          0   4   7 9
             / \
            3   5

# Pseudocode
1.	create dfs functions
   - if root == NULL, then return root
   - else if root == p, then return p
   - else if root == q, then return q
   - visit left child
   - visit right child
   - if left child != NULL && right child != NULL, return root
   - else if left child != NULL return left
   - else if right child != NULL return right
   - else return NULL

Time Complexity : O(N)
N -> total node in the tree

Memory Commplexity : O(H)
H -> height of the tree


*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return root;
        } else if (root == p) {
            return p;
        } else if (root == q) {
            return q;
        }

        TreeNode* leftChild = lowestCommonAncestor(root -> left, p, q);
        TreeNode* rightChild = lowestCommonAncestor(root -> right, p, q);

        if (leftChild != NULL && rightChild != NULL) {
            return root;
        } else if (leftChild != NULL) {
            return leftChild;
        } else if (rightChild != NULL) {
            return rightChild;
        } else {
            return NULL;
        }
    }
};
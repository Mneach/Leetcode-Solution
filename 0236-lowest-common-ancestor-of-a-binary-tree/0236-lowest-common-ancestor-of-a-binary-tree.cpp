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
1.	we need to visit the child first, then the current node
2. if the current node is not equal to p or q, just return NULL
3. otherwise return the current node, because the current code might be our answer
4. if left child and right child is not equal to NULL, we should return the parent

# Postorder Tranversal

# Simulation
p = 5
q = 1

           3
          / \
         5   1
        /\   /\
       6  2  0 8
         /\
        7  4

Time Complexity : O(N)
N -> total nodes

Memory Complexity : O(1)

*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return root;
        } else if (root == p) {
            return root;
        } else if (root == q) {
            return root;
        }

        // do post order traversal
        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);

        if (left != NULL && right != NULL) {
            return root;
        } else if (left != NULL) {
            return left;
        } else {
            return right;
        }
    }
};
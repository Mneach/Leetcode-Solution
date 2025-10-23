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
1.	we are given perfect binary tree
   - every node from level 0 until level h - 1, will have 2 childs
   - at the level h, will have 0 childs
2. we need to reverse the node values at each odd level of the tree
3. level will be start at 0, so root should be at level 0
4. we should swap the value of the node
   - because of we don't want to change the nodes at even level


# Simulation


          0
      /          \
     2            1
    /   \      /   \
   3     4     5     6
  /\    /\    /\    / \
 7  8  9 10  11 12 13 14


post order traversal start from left subtree and right subtree

post order traversal left sub tree

-> visit(7) at level 3
-> visit(8) at level 3
-> visit(3) at level 2
-> visit(9) at level 3
-> visit(10) at level 3
-> visit(4) at level 2
-> visit(2) at level 1


post order traversal right sub tree
-> visit(14) at level 3
-> visit(13) at level 3
-> visit(6) at level 2
-> visit(12) at level 3
-> visit(11) at level 3
-> visit(5) at level 2
-> visit(1) at level 1


# Pseudocode
1.	create post order traversal (leftRoot, rightRoot, level)
   - if (leftRoot == NULL && rightRoot == NULL)
     - return
   - move to the left child for left root and right child for right root
     - postOrderTraversal(leftRoot -> left, rightRoot -> right, level + 1)
   - move to the right child for left root and left child for right root
     - postOrderTraversal(leftRoot -> right, rightRoot -> left, level + 1)
   - if (level % 2 == 1)
     - swap leftRoot value with rightRoot value
2. call the post order traversal function
3. return the root

Time Complexity : O(N)
N -> total nodes in the perfect tree

Memory Complexity : O(H)
H -> height of the perfect tree


*/

class Solution {
private:
    void postOrderTraversal(TreeNode* leftRoot, TreeNode* rightRoot, int level) {
        if (leftRoot == NULL && rightRoot == NULL) {
            return;
        }

        postOrderTraversal(leftRoot -> left, rightRoot -> right, level + 1);
        postOrderTraversal(leftRoot -> right, rightRoot -> left, level + 1);

        if (level % 2 == 1) {
            swap(leftRoot -> val, rightRoot -> val);
        }
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (root == NULL) {
            return root;
        }

        postOrderTraversal(root -> left, root -> right, 1);

        return root;
    }
};
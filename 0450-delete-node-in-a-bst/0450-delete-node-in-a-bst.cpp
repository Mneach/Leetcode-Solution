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
1.	search node using dfs and also need to follow the bst rules
2. if the node is found, delete the node
3. if we cannot found the node, just do nothing
4. to delete the node, we also need to find the highest value from left sub tree or the lowest value from right sub tree
   - keep in mind if the current node doesn't have child, then return NULL
   - if the current node only have left child, then delete the current node and return left child
   - if the current node only have right child, the delete the current node and return right child

# Simulation

key = 2

      10
     / \ 
    5   16
     \   \
      8   17
     / \
    6   9

key = 16

      10
     / \
    5   17
   / \   
  2   8   
     / \
    6   9


key = 5

      10
     / \
    6   17
   / \
  2   8
       \
        9



# Pseudocode
1.	create deleteBST functions (root, key)
   - if root == NULL, return 
   - else if root -> val < key that we want to search, move into the right child
   - else if root -> val > key that we want to search, move into the left child
   - else
     - if the root doesn't have child
       - delete the root
     - else if root only have left child
       - swap root val with left child val
       - delete the left child
       - return root
     - else if root only have right child
       - swap the root with right child
       - delete the right child
       - return the root
     - else
       - get the node with minimum value from the right sub tree
       - swap the root -> val with node -> val
       - deleteBST(root -> right, root -> val)
   - return root

Time Complexity : O(N)
N -> total nodes in the binary tree

Memory Complexity : O(H)
H -> height of the binary tree


*/

class Solution {
private:
    TreeNode* getMinNodeFromRightChild(TreeNode* root) {
        
        while (root -> left != NULL) {
            root = root ->left;
        }

        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return root;
        } else if (root -> val < key) {
            root -> right = deleteNode(root -> right, key);
        } else if (root -> val > key) {
            root -> left = deleteNode(root -> left, key);
        } else {
            if (root -> left == NULL && root -> right == NULL) {
                delete(root);
                return NULL;
            } else if (root -> left != NULL && root -> right == NULL) {
                TreeNode* leftChild = root -> left;
                delete(root);

                return leftChild;
            } else if (root -> left == NULL && root -> right != NULL) {
                TreeNode* rightChild = root -> right;
                delete(root);

                return rightChild;
            } else {
                TreeNode* minNode = getMinNodeFromRightChild(root -> right);
                root -> val = minNode -> val;

                root -> right = deleteNode(root -> right, minNode -> val);
            }
        }

        return root;
    }
};
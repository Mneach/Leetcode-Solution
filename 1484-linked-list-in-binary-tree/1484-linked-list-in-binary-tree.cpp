/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
1.	we are give binary tree "root" and linked list "head"
2.	Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the binary tree otherwise return False.

# DFS (pre order traversal)

# Simulation


       1
     /   \
    4     4
     \    /
      2   2
     /   / \
    1   6   8
           / \
          1   3

head = [4,2,6]

process 1 : 
current node = 1
head of linked list = 4

visit(1) -> visit(4) - move to the left child
         -> visit(4) - move to the right child

process 2 : 
current node = 4
head of linked list = 4

check identical data = false
⦁	check if the current node can satisfy the condition

       1
     /   \
    4     4
     \    /
      2   2
     /   / \
    1   6   8
           / \
          1   3

current node = 1
current linked list value = 6

process 3 : 
current node = 2
current linked list value = 4

process 4 : 
current node = 1
current linked list = 4

process 5 : 
current node = 4 (right child of node 1)
current linked list = 4

check indentical data = true
⦁	check if the current node can satisfy the condition
       1
     /   \
    4     4
     \    /
      2   2
     /   / \
    1   6   8
           / \
          1   3

current node = 8
current linked list value = 6

path (4 -> 2 -> 6) = true

path (4 -> 2 -> 8) = false

Time Complexity : O(N * M)
N -> total nodes in the tree
M -> total nodes in the linked list

Memory Complexity : O(H * M)
H -> height of the tree
M -> total node in the linked list


*/

class Solution {

    bool checkIdentical(ListNode* head, TreeNode* root) {
        if (head == NULL && root != NULL) {
            return true;
        } else if (head != NULL && root == NULL) {
            return false;
        } else if(head == NULL && root == NULL) {
            return true;
        }

        if (head -> val != root -> val) {
            return false;
        }

        bool leftResult = checkIdentical(head -> next, root -> left);
        bool rightResult = checkIdentical(head -> next, root -> right);

        return leftResult || rightResult;
    }

public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == NULL) {
            return false;
        }

        if (head -> val == root -> val) {
            bool result = checkIdentical(head, root);

            if (result) {
                return result;
            }
        }

        bool leftResult = isSubPath(head, root -> left);
        bool rightResult = isSubPath(head, root -> right);

        return leftResult || rightResult;
    }
};
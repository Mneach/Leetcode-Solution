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
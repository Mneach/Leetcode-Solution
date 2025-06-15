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
public:
    int findTilt(TreeNode* root) {
        int totalTilt = 0;
        calculateSubtreeSum(root, totalTilt);
        return totalTilt;
    }

private:
    int calculateSubtreeSum(TreeNode* node, int& totalTilt) {
        if (!node) {
            return 0;
        }

        int leftSum = calculateSubtreeSum(node->left, totalTilt);
        int rightSum = calculateSubtreeSum(node->right, totalTilt);
        
        totalTilt += abs(leftSum - rightSum);
        
        return node->val + leftSum + rightSum;
    }
};
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
private:
    TreeNode* buildBSTFromSortedArray(const vector<int>& nums, int left, int right) {
        // Base case: when the subarray has no elements
        if (left >= right) {
            return nullptr;
        }
        
        // Find the middle index to make it the root
        int mid = left + (right - left) / 2;
        
        // Create the root node with the middle element
        TreeNode* root = new TreeNode(nums[mid]);
        
        // Recursively build left and right subtrees
        root->left = buildBSTFromSortedArray(nums, left, mid);
        root->right = buildBSTFromSortedArray(nums, mid + 1, right);
        
        return root;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBSTFromSortedArray(nums, 0, nums.size());
    }
};
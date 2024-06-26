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

    void helper(vector<int> &arr, TreeNode* root){
        
        if(root){
            helper(arr, root -> left);
            arr.push_back(root->val);
            helper(arr, root -> right);
        }
    }

    TreeNode* constructBST(vector<int> &arr, int start, int end){
        if(start <= end){

            int mid = start + (end - start) / 2;

            TreeNode* left = constructBST(arr, start, mid - 1);
            TreeNode* right = constructBST(arr, mid + 1, end);

            return new TreeNode(arr[mid], left, right);
        }

        return NULL;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        helper(arr, root);

        root = constructBST(arr, 0, arr.size() - 1);

        return root;
    }
};
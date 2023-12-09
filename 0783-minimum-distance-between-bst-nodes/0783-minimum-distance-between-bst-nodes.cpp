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
    
    int minAnswer = INT_MAX;
    
    void inOrder(TreeNode* root, vector<int> &arr){
        if(root){
            inOrder(root->left, arr);
            arr.push_back(root->val);
            inOrder(root->right, arr);
        }
    }
    
    int minDiffInBST(TreeNode* root) {
        vector<int> arr;
        
        inOrder(root, arr);
        
        sort(arr.begin(), arr.end());
        
        int answer = INT_MAX;
        
        for(int i = 0; i < arr.size() - 1; i++){
            answer = min(answer,arr[i + 1] - arr[i]);
        }
        
        return answer;
    }
};
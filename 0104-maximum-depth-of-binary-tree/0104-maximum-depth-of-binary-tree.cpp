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
    
    int answer = 0;
    
    void PostOrder(TreeNode* root, int current){
        if(root != NULL){
            PostOrder(root->left, current + 1);
            PostOrder(root->right, current + 1);
            current += 1;
            answer = max(current , answer);
        }
    }
    
    int maxDepth(TreeNode* root) {
        int current = 0;
        PostOrder(root, current);
        return answer;
    }
};
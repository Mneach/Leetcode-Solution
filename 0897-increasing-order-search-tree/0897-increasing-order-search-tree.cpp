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
    
    void InOrder(TreeNode *root, stack<int>& stack){
        if(root != NULL){
            InOrder(root->left, stack);
            stack.push(root->val);
            InOrder(root->right, stack);
        }
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        
        stack<int> stack;
        InOrder(root, stack);
        
        TreeNode* answer = new TreeNode(stack.top());
        stack.pop();
        
        while(stack.empty() == false){
            TreeNode* temp = new TreeNode(stack.top());
            temp->right = answer;
            answer = temp;
            stack.pop();
        }
        
        return answer;    
    }
};
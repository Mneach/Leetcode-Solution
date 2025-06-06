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
    
    vector<int> rightSideView(TreeNode* root) {
        
        // return empty if root is null;
        if(!root) return {};
        
        vector<int> answer;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            
            // iterate over all level
            for(int i = q.size(); i > 0; i--){
                TreeNode *node = q.front();
                q.pop();
                
                if(i == 1) answer.push_back(node->val);
                
                if(node->left){
                    q.push(node->left);
                }
                
                if(node->right){
                    q.push(node->right);
                }
            }
        }
        
        return answer;
    }
};
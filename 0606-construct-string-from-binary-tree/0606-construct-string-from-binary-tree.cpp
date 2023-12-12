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
    
    void preOrder(TreeNode* root, string &answer){
        if(root){
            if(root->left && root->right){
                answer += "(" + to_string(root->val);
                preOrder(root->left, answer);
                preOrder(root->right, answer);
                answer += ")";    
            }else if(root->left && root->right == NULL){
                answer += "(" + to_string(root->val);
                preOrder(root->left, answer);
                answer += ")";
            }else if(root->right && root->left == NULL){
                answer += "(" + to_string(root->val) + "()";
                preOrder(root->right, answer);
                answer += ")";
            }else{
                answer += "(" + to_string(root->val) + ")";
            }
        }
    }
    
    string tree2str(TreeNode* root) {
        
        string answer = "";
        preOrder(root, answer);
        //preOrder(root->left, answer);
        //preOrder(root->right, answer);
        
        cout << answer << endl;
        return answer.substr(1, answer.size() - 2);
    }
};
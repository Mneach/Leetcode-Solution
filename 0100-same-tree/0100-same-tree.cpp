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
    
    bool answer = true;
    
    void inOrder(TreeNode *p, TreeNode *q){
        
        if(p && q){
            inOrder(p->left, q->left);
            if(p -> val != q -> val){
                answer = false;
            }
            inOrder(p->right, q->right);
        }else if(p == NULL && q == NULL){
            return;
        }else{
            answer = false;
            return;
        }
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        inOrder(p, q);
        return answer;
    }
};
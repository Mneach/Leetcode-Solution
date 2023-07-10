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
    
    void count(TreeNode* root, int& totalNode, int& totalValue){
        if(root){
            totalNode++;
            totalValue += root->val;
            count(root->left, totalNode, totalValue);
            count(root->right, totalNode, totalValue);
        }
    }
    
    void dfs(TreeNode* root, int &answer){
        if(root){
            dfs(root->left, answer);
            dfs(root->right, answer);
            
            int totalNodeLeft = 0;
            int totalNodeRight = 0;
            int totalValueNodeLeft = 0;
            int totalValueNodeRight = 0;
            count(root->left, totalNodeLeft, totalValueNodeLeft); 
            count(root->right, totalNodeRight, totalValueNodeRight); 
            
            int totalValue = totalValueNodeLeft + totalValueNodeRight + root->val;
            int totalNode = totalNodeLeft + totalNodeRight + 1;
            
            cout << totalValue << " " << totalNode << endl;
            if(root->val == totalValue / totalNode) answer++;
        }
    }
    
    int averageOfSubtree(TreeNode* root) {
       int answer = 0;
        
       dfs(root, answer);
        
        return answer;
    }
};
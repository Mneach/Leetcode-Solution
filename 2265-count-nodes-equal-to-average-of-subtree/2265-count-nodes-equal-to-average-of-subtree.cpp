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
    
    pair<int,int> dfs(TreeNode* root, int &answer){
        if(root){
            pair<int,int> leftResult = dfs(root->left, answer); 
            int sumValueLeft = leftResult.first;
            int sumNodeLeft = leftResult.second;
            
            pair<int,int> rightResult = dfs(root->right, answer);
            int sumValueRight = rightResult.first;
            int sumNodeRight = rightResult.second;
            
            int sumValue = sumValueLeft + sumValueRight + root->val;
            int sumNode = sumNodeLeft + sumNodeRight + 1; 
            
            cout << sumNode << " " << sumValue << endl; 
            if(root->val == sumValue / sumNode) answer++;
            
            return {sumValue, sumNode};
        }else{
            return {0, 0};
        }
    }
    
    int averageOfSubtree(TreeNode* root) {
       int answer = 0;
        
       dfs(root, answer);
        
        return answer;
    }
};
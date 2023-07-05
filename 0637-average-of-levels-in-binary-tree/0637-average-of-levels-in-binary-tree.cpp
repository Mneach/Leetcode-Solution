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
    
    void dfs(TreeNode* root, map<int, vector<int>>& hashmap, int currDepth){
        if(root){
            dfs(root->left, hashmap, currDepth + 1);
            dfs(root->right, hashmap, currDepth + 1);
            hashmap[currDepth].push_back(root->val);
        }
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        map<int, vector<int>> hashmap;
        dfs(root, hashmap, 0);
        
        vector<double> answer;
        
        for(auto x : hashmap){
            
            double totalNodeValue = 0;
            for(auto nodeValue : x.second){
                totalNodeValue += nodeValue;
            }
            
            totalNodeValue /= x.second.size();
            answer.push_back(totalNodeValue);
        }
        
        return answer;
    }
};
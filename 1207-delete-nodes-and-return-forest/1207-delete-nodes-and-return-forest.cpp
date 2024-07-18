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

    TreeNode* search(TreeNode* root, unordered_map<int,int> &deleted, vector<TreeNode*> &answer){
        
        if(!root) return nullptr;

        root -> left = search(root -> left, deleted, answer);
        root -> right = search(root -> right, deleted, answer);

        if(deleted[root -> val] > 0){
            cout << root -> val << endl;
            if(root -> left) {
                answer.push_back(root -> left);
            }
            
            if(root -> right) {
                answer.push_back(root -> right);
            }

            delete root;
            return nullptr;
        }

        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> answer;
        unordered_map<int,int> deleted;

        for(auto data : to_delete) deleted[data]++;

        root = search(root, deleted, answer);

        if(root){
            answer.push_back(root);
        }

        return answer;
    }
};
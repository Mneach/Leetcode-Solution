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

    pair<vector<int>, int> recursive(TreeNode* root, int distance){
        if(root){
            pair<vector<int>, int> left = recursive(root -> left, distance);
            pair<vector<int>, int> right = recursive(root -> right, distance);

            vector<int> temp;

            for(int i = 0; i < left.first.size(); i++){
                int first = left.first[i];
                for(int j = 0; j < right.first.size(); j++){
                    int second = right.first[j];

                    if(first + second <= distance){
                        answer++;
                    }
                }

                temp.push_back(first + 1);
            }

            for(int i = 0; i < right.first.size(); i++){
                temp.push_back(right.first[i] + 1);
            }

            if(left.second == 0 && right.second == 0){
                temp.push_back(1);
            }

            return make_pair(temp, 1);
        }
        vector<int> temp;
        return make_pair(temp, 0);
    }

    int countPairs(TreeNode* root, int distance) {
        pair<vector<int>, int> res = recursive(root, distance);

        return answer;
    }
};
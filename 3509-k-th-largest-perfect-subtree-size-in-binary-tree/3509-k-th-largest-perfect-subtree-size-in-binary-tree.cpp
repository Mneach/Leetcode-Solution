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

    int postOrder(vector<int> &answer, TreeNode* root){
        if(root){
            // cout << root -> val << endl;
            // move to the left
            int left = postOrder(answer, root -> left);

            // move to the right
            int right = postOrder(answer, root -> right);

            if(left == -10 && right == -10){
                answer.push_back(1);
                return 1;
            }else if(left == -1 || right == -1){
                answer.push_back(-1);
                return -1;
            }

            int res = -1;
            if(left == right){
                res = (left + right + 1);
            }

            answer.push_back(res);
            return res;
        }

        return -10;
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {

        vector<int> answer;    

        postOrder(answer, root);

        sort(answer.begin(), answer.end(), greater<int>());

        // for(auto data : answer){
        //     cout << data << " ";
        // }
        
        if(k > answer.size()){
            return -1;
        }

        return answer[k - 1]; 
    }
};
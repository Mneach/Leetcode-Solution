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
    long long kthLargestLevelSum(TreeNode* root, int k) {

        if(root -> left == NULL && root -> right == NULL){
            if(k == 1) return root -> val;
            else return -1;
        }
        
        priority_queue<long long> pq;
        long long res = 0;
        int level = 0;

        // tree node , tree level
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        bool check = true;

        while(q.empty() == false){
            auto node = q.front();
            TreeNode* treeNode = node.first;
            q.pop();

            if(node.second != level){
                // put the sum into the pq
                pq.push(res);
                level = node.second;
                res = node.first -> val;
            }else{
                res += treeNode -> val;
            }

            if(treeNode -> left != NULL){
                q.push(make_pair(treeNode -> left, node.second + 1));
            }
            
            if(treeNode -> right != NULL){
                q.push(make_pair(treeNode -> right, node.second + 1));
            }
        }

        pq.push(res);
        long long answer = -1;

        while(pq.size() > 0 && k > 0){
            if(k == 1){
                answer = pq.top();
            }
            k--;
            pq.pop();
        }

        return answer;
    }
};

/*
How to solve
1. need to traverse the tree level by level -> we can use BFS algorithm with queue
2. we also need to mark the current tree level
3. if the current tree level is not equal to the next tree level -> add the current level sum to pq
4. looping while k > 0
   4.1 every loop we need to pop until k == 0

Time complexity : O(N) + (totalLevel * logTotalLevel)
O(N) -> where n is equal to total data in the tree, we need to traverse from root until last child
O(totalLevel * logTotalLevel) -> we need to push the sum from every level to the pq

Memory complexity : 
O(N) -> we need to traverse the tree from root until last child
O(totalLevel) -> we need to save sum from every level to pq
*/

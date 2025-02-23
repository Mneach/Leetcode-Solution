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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        stack<TreeNode*> st;
        int postOrderIndex = 0;
        
        for (int i = 0; i < preorder.size(); i++) {
            TreeNode* newNode = new TreeNode(preorder[i]);
            st.push(newNode);

            while (postOrderIndex < postorder.size() && st.top() -> val == postorder[postOrderIndex]) {
                TreeNode* currentNode = st.top();
                st.pop();

                if (st.size() == 0) return currentNode;

                TreeNode* parent = st.top();
                if (parent -> left == NULL) {
                    parent -> left = currentNode;
                } else {
                    parent -> right = currentNode;
                }

                postOrderIndex++;
            }
        }

        return NULL;
    }
};
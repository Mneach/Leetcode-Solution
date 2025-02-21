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
class FindElements {
private:
    vector<int> bucket;
public:
    void recover(TreeNode* root, int index) {
        if (root) {
            if (root -> left) {
                root -> left -> val = (2 * root -> val) + 1;
                bucket[root -> left -> val] = root -> left -> val;
                recover(root -> left, root -> left -> val);
            }

            if (root -> right) {
                root -> right -> val = (2 * root -> val) + 2;
                bucket[root -> right -> val] = root -> right -> val;
                recover(root -> right, root -> right -> val);
            }
        }
    }

    FindElements(TreeNode* root) {
        for (int i = 0; i < 1e6 + 1; i++) {
            bucket.push_back(-1);
        }
        root -> val = 0;
        bucket[root -> val] = root -> val;
        recover(root, root -> val);
    }
    
    bool find(int target) {
        if (bucket[target] >= 0) return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
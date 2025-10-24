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

class Node {
public:
    TreeNode* root;    
    int sum;

    Node(TreeNode* root, int sum) {
        this -> root = root;
        this -> sum = sum;
    }

    int getChildSum() {
        int childSum = 0;
        if (this -> root -> left) {
            childSum += this -> root -> left -> val;
        }

        if (this -> root -> right) {
            childSum += this -> root -> right -> val;
        }

        return childSum;
    }
};

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<Node*> q;

        // parent node value | child values
        unordered_map<int,int> bucket;

        if (root == NULL) {
            return root;
        }

        q.push(new Node(root, root -> val));
        int currentLevelSum = root -> val;

        while (q.empty() == false) {
            int size = q.size();
            int nextLevelSum = 0;

            for (int i = 0; i < size; i++) {
                Node* currentNode = q.front();
                q.pop();

                if (currentNode -> root -> left) {
                    q.push(new Node(currentNode -> root -> left, currentNode -> getChildSum()));
                    nextLevelSum += currentNode -> root -> left -> val;
                }

                if (currentNode -> root -> right) {
                    q.push(new Node(currentNode -> root -> right, currentNode -> getChildSum()));
                    nextLevelSum += currentNode -> root -> right -> val;
                }

                currentNode -> root -> val = currentLevelSum - currentNode -> sum;
            }

            currentLevelSum = nextLevelSum;
        }

        return root;
    }
};
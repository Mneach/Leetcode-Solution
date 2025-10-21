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
private:
    TreeNode* currentNode;
    bool isRoot; 
public:
    Node(TreeNode* currentNode, bool isRoot) {
        this -> isRoot = isRoot;
        this -> currentNode = currentNode;
    }

    void setRoot(bool isRoot) {
        this -> isRoot = isRoot;
    }

    bool getRoot() {
        return this -> isRoot;
    }

    TreeNode* getCurrentNode() {
        return this -> currentNode;
    }
};

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, Node*> hashMap;        

        for (auto description : descriptions) {
            int parentKey = description[0];
            int childKey = description[1];
            int isLeft = description[2];

            // if the parent is not exists
            // we need to create the parent node
            if (hashMap.count(parentKey) == 0) {
                TreeNode* parent = new TreeNode(parentKey);
                Node* newNode = new Node(parent, true);
                hashMap[parentKey] = newNode; 
            }
                
            if (isLeft) {
                // if the new node already exists in the hashmap
                // then update the child isRoot property to false
                // otherwise create a new node
                if (hashMap.count(childKey) == 0) {
                    TreeNode* leftChild = new TreeNode(childKey);
                    hashMap[parentKey] -> getCurrentNode() -> left = leftChild;

                    Node* newNode = new Node(leftChild, false);
                    hashMap[childKey] = newNode;
                } else {
                    hashMap[childKey] -> setRoot(false);
                    hashMap[parentKey] -> getCurrentNode() -> left = hashMap[childKey] -> getCurrentNode();
                }
            } else {
                // if the new node already exists in the hashmap
                // then update the child isRoot property to false
                // otherwise create a new node
                if (hashMap.count(childKey) == 0) {
                    TreeNode* rightChild = new TreeNode(childKey);
                    hashMap[parentKey] -> getCurrentNode() -> right = rightChild;

                    Node* newNode = new Node(rightChild, false);
                    hashMap[childKey] = newNode;
                } else {
                    hashMap[childKey] -> setRoot(false);
                    hashMap[parentKey] -> getCurrentNode() -> right = hashMap[childKey] -> getCurrentNode();
                }
            }
        }

        // find the root
        TreeNode* result = NULL;

        for (auto [key, node] : hashMap) {
            
            if (node -> getRoot() == true) {
                result = node -> getCurrentNode();
                break;
            }
        }

        return result;
    }
};
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return root;

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        int previousLevelSum = root->val;

        while (!nodeQueue.empty()) {
            int levelSize = nodeQueue.size();
            int currentLevelSum = 0;

            // Process each node at the current level.
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = nodeQueue.front();
                nodeQueue.pop();
                
                // Replace current node's value with cousin sum.
                currentNode->val = previousLevelSum - currentNode->val;

                // Calculate sibling sum.
                int siblingSum = calculateSiblingSum(currentNode);

                // Process left child.
                if (currentNode->left) {
                    currentLevelSum += currentNode->left->val;
                    currentNode->left->val = siblingSum;
                    nodeQueue.push(currentNode->left);
                }

                // Process right child.
                if (currentNode->right) {
                    currentLevelSum += currentNode->right->val;
                    currentNode->right->val = siblingSum;
                    nodeQueue.push(currentNode->right);
                }
            }

            previousLevelSum = currentLevelSum; // Prepare for the next level.
        }

        return root;
    }

private:
    // Helper function to calculate the sum of a node's children (sibling sum).
    int calculateSiblingSum(TreeNode* node) {
        int leftVal = (node->left != nullptr) ? node->left->val : 0;
        int rightVal = (node->right != nullptr) ? node->right->val : 0;
        return leftVal + rightVal;
    }
};

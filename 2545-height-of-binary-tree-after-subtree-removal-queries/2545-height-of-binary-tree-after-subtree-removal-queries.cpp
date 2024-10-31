class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        const int MAX_NODES = 100000;
        
        // Data structures to store node depths and subtree heights
        vector<int> nodeDepths(MAX_NODES + 1, 0);
        vector<int> subtreeHeights(MAX_NODES + 1, 0);
        
        // Vectors to store the first and second largest heights at each level
        vector<int> maxHeightAtLevel(MAX_NODES + 1, 0);
        vector<int> secondMaxHeightAtLevel(MAX_NODES + 1, 0);

        // Run DFS to populate depth and height information
        calculateHeightsAndDepths(root, 0, nodeDepths, subtreeHeights, maxHeightAtLevel, secondMaxHeightAtLevel);

        vector<int> results;
        results.reserve(queries.size());

        // Process each query by calculating the tree height if the node is removed
        for (int node : queries) {
            int level = nodeDepths[node];

            if (subtreeHeights[node] == maxHeightAtLevel[level]) {
                results.push_back(level + secondMaxHeightAtLevel[level] - 1);
            } else {
                results.push_back(level + maxHeightAtLevel[level] - 1);
            }
        }

        return results;
    }

private:
    // DFS to calculate node depths and subtree heights
    int calculateHeightsAndDepths(TreeNode* node, int level, vector<int>& nodeDepths,
                                  vector<int>& subtreeHeights, vector<int>& maxHeightAtLevel,
                                  vector<int>& secondMaxHeightAtLevel) {
        if (!node) return 0;

        nodeDepths[node->val] = level;

        int leftHeight = calculateHeightsAndDepths(node->left, level + 1, nodeDepths, subtreeHeights, maxHeightAtLevel, secondMaxHeightAtLevel);
        int rightHeight = calculateHeightsAndDepths(node->right, level + 1, nodeDepths, subtreeHeights, maxHeightAtLevel, secondMaxHeightAtLevel);
        int currentHeight = 1 + max(leftHeight, rightHeight);

        subtreeHeights[node->val] = currentHeight;

        updateMaxHeightsAtLevel(level, currentHeight, maxHeightAtLevel, secondMaxHeightAtLevel);

        return currentHeight;
    }

    // Update the first and second largest heights at a given level
    void updateMaxHeightsAtLevel(int level, int currentHeight, vector<int>& maxHeightAtLevel, vector<int>& secondMaxHeightAtLevel) {
        if (currentHeight > maxHeightAtLevel[level]) {
            secondMaxHeightAtLevel[level] = maxHeightAtLevel[level];
            maxHeightAtLevel[level] = currentHeight;
        } else if (currentHeight > secondMaxHeightAtLevel[level]) {
            secondMaxHeightAtLevel[level] = currentHeight;
        }
    }
};

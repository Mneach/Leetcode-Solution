class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& tree1_edges,
                               vector<vector<int>>& tree2_edges, 
                               int k) {
        // Build both trees
        auto tree1 = buildTree(tree1_edges);
        auto tree2 = buildTree(tree2_edges);
        
        // Calculate counts for each node in both trees
        vector<int> tree1_counts = calculateNodeCounts(tree1, k);
        vector<int> tree2_counts = calculateNodeCounts(tree2, k - 1);
        
        // Find the maximum count in tree2
        int max_tree2_count = *max_element(tree2_counts.begin(), tree2_counts.end());
        
        // Combine results
        vector<int> result(tree1_counts.size());
        for (int i = 0; i < result.size(); i++) {
            result[i] = tree1_counts[i] + max_tree2_count;
        }
        
        return result;
    }

private:
    // Build adjacency list representation of a tree
    vector<vector<int>> buildTree(const vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> tree(n);
        for (const auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        return tree;
    }
    
    // Calculate reachable nodes within distance k for each node
    vector<int> calculateNodeCounts(const vector<vector<int>>& tree, int k) {
        int n = tree.size();
        vector<int> counts(n);
        for (int i = 0; i < n; i++) {
            counts[i] = countReachableNodes(i, -1, tree, k);
        }
        return counts;
    }
    
    // DFS to count reachable nodes within remaining distance
    int countReachableNodes(int node, int parent, 
                           const vector<vector<int>>& tree, 
                           int remaining_distance) {
        if (remaining_distance < 0) {
            return 0;
        }
        
        int count = 1;  // Count the current node
        
        for (int neighbor : tree[node]) {
            if (neighbor == parent) {
                continue;  // Skip the parent to avoid going back
            }
            count += countReachableNodes(neighbor, node, tree, remaining_distance - 1);
        }
        
        return count;
    }
};
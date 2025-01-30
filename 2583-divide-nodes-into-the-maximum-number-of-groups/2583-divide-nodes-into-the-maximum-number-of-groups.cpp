class UnionFind {
private:
    vector<int> parent;
    vector<int> depth;

public:
    UnionFind(int n) : parent(n, -1), depth(n, 0) {}

    int find(int node) {
        while (parent[node] != -1) node = parent[node];
        return node;
    }

    void unite(int node1, int node2) {
        int root1 = find(node1);
        int root2 = find(node2);

        if (root1 == root2) return;

        if (depth[root1] < depth[root2]) swap(root1, root2);
        parent[root2] = root1;

        if (depth[root1] == depth[root2]) depth[root1]++;
    }
};

class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        UnionFind uf(n);

        // Build the adjacency list and apply Union-Find for each edge
        for (const auto& edge : edges) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            uf.unite(u, v);
        }

        unordered_map<int, int> maxGroupsPerComponent;

        // For each node, calculate the maximum number of groups for its component
        for (int node = 0; node < n; ++node) {
            int numGroups = calculateGroups(adjList, node, n);
            if (numGroups == -1) return -1;  // If invalid split, return -1
            int root = uf.find(node);
            maxGroupsPerComponent[root] = max(maxGroupsPerComponent[root], numGroups);
        }

        // Calculate the total number of groups across all components
        int totalGroups = 0;
        for (const auto& [root, numGroups] : maxGroupsPerComponent) {
            totalGroups += numGroups;
        }
        return totalGroups;
    }

private:
    int calculateGroups(const vector<vector<int>>& adjList, int srcNode, int n) {
        queue<int> q;
        vector<int> layer(n, -1);
        q.push(srcNode);
        layer[srcNode] = 0;
        int maxLayer = 0;

        // Perform BFS to calculate the number of layers (groups)
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int currentNode = q.front();
                q.pop();
                for (int neighbor : adjList[currentNode]) {
                    if (layer[neighbor] == -1) {
                        layer[neighbor] = maxLayer + 1;
                        q.push(neighbor);
                    } else if (layer[neighbor] == maxLayer) {
                        return -1;  // Invalid partition
                    }
                }
            }
            maxLayer++;
        }
        return maxLayer;
    }
};
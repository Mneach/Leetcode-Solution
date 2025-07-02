class Solution {
private:
    struct TreeInfo {
        vector<int> color;
        vector<int> count;
    };

    TreeInfo buildTreeInfo(const vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> children(n);
        
        // Build adjacency list
        for (const auto& edge : edges) {
            children[edge[0]].push_back(edge[1]);
            children[edge[1]].push_back(edge[0]);
        }
        
        vector<int> color(n);
        int color_count = dfs(0, -1, 0, children, color);
        
        return {color, {color_count, n - color_count}};
    }

    int dfs(int node, int parent, int depth, 
            const vector<vector<int>>& children, vector<int>& color) {
        // Assign color based on depth parity (0 or 1)
        color[node] = depth % 2;
        int count = (color[node] == 0) ? 1 : 0;
        
        for (int child : children[node]) {
            if (child != parent) {
                count += dfs(child, node, depth + 1, children, color);
            }
        }
        
        return count;
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        TreeInfo tree1 = buildTreeInfo(edges1);
        TreeInfo tree2 = buildTreeInfo(edges2);
        
        int n = edges1.size() + 1;
        vector<int> result(n);
        int max_color2 = max(tree2.count[0], tree2.count[1]);
        
        for (int i = 0; i < n; ++i) {
            result[i] = tree1.count[tree1.color[i]] + max_color2;
        }
        
        return result;
    }
};
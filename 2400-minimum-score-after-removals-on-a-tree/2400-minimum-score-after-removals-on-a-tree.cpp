class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        
        // Build adjacency list
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        // Initialize variables for DFS
        vector<int> xor_sum(n), in_time(n), out_time(n);
        int timer = 0;
        
        // Perform DFS to calculate XOR sums and timings
        function<void(int, int)> dfs = [&](int node, int parent) {
            in_time[node] = timer++;
            xor_sum[node] = nums[node];
            
            for (int neighbor : adj[node]) {
                if (neighbor != parent) {
                    dfs(neighbor, node);
                    xor_sum[node] ^= xor_sum[neighbor];
                }
            }
            
            out_time[node] = timer;
        };
        
        dfs(0, -1);
        
        int min_score = INT_MAX;
        
        // Check all pairs of nodes
        for (int u = 1; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                int part1, part2, part3;
                
                if (is_ancestor(u, v, in_time, out_time)) {
                    // u is ancestor of v
                    part1 = xor_sum[0] ^ xor_sum[u];
                    part2 = xor_sum[u] ^ xor_sum[v];
                    part3 = xor_sum[v];
                } else if (is_ancestor(v, u, in_time, out_time)) {
                    // v is ancestor of u
                    part1 = xor_sum[0] ^ xor_sum[v];
                    part2 = xor_sum[v] ^ xor_sum[u];
                    part3 = xor_sum[u];
                } else {
                    // u and v are in different subtrees
                    part1 = xor_sum[0] ^ xor_sum[u] ^ xor_sum[v];
                    part2 = xor_sum[u];
                    part3 = xor_sum[v];
                }
                
                int current_score = calculate_score(part1, part2, part3);
                min_score = min(min_score, current_score);
            }
        }
        
        return min_score;
    }

private:
    bool is_ancestor(int u, int v, const vector<int>& in_time, const vector<int>& out_time) {
        return in_time[u] < in_time[v] && out_time[u] > in_time[v];
    }
    
    int calculate_score(int a, int b, int c) {
        int max_val = max({a, b, c});
        int min_val = min({a, b, c});
        return max_val - min_val;
    }
};
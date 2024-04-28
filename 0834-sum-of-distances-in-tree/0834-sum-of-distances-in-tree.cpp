class Solution {
private:
    std::vector<int> ans, count;
    std::vector<std::unordered_set<int>> graph;
    int N;

public:
    std::vector<int> sumOfDistancesInTree(int N, std::vector<std::vector<int>>& edges) {
        this->N = N;
        graph.resize(N);
        ans.resize(N, 0);
        count.resize(N, 1);

        for (int i = 0; i < N; ++i)
            graph[i] = std::unordered_set<int>();
        
        for (auto& edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        
        dfs(0, -1);
        dfs2(0, -1);
        return ans;
    }

    void dfs(int node, int parent) {
        for (int child : graph[node]) {
            if (child != parent) {
                dfs(child, node);
                count[node] += count[child];
                ans[node] += ans[child] + count[child];
            }
        }
    }

    void dfs2(int node, int parent) {
        for (int child : graph[node]) {
            if (child != parent) {
                ans[child] = ans[node] - count[child] + N - count[child];
                dfs2(child, node);
            }
        }
    }
};

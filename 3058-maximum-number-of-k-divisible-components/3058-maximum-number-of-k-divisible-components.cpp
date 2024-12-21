class Solution {
public:

    long long int dfs(int &answer, vector<vector<int>> &adj, int current, long long int total, int parent, vector<int> &values, int k) {
        total = values[current];

        for (auto child : adj[current]) {
            if (child != parent) {
               total += dfs(answer, adj, child, total, current, values, k);
            }
        }

        if (total % k == 0) {
            answer++;
        }

        return total;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {

        vector<vector<int>> adj(n);

        for (auto edge : edges) {
            int source = edge[0];
            int dest = edge[1];

            adj[source].push_back(dest);
            adj[dest].push_back(source);
        }

        int answer = 0;

        dfs(answer, adj, 0, 0, -1, values, k);

        return answer;
    }
};
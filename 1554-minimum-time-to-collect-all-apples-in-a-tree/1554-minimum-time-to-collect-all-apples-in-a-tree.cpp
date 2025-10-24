class Solution {
private:
    int dfs(vector<vector<int>> &adjList, vector<bool> &hasApple, int node, int parent) {
        int total = 0;
        for (auto nextNode : adjList[node]) {
            if (nextNode == parent) {
                continue;
            }

            total += dfs(adjList, hasApple, nextNode, node);
        }

        if ((total != 0 || hasApple[node] == true) && node != 0) {
            total += 2;
        }

        return total;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adjList(n);

        // convert edges to adj list
        for (auto edge : edges) {
            int source = edge[0];
            int dest = edge[1];

            adjList[source].push_back(dest);
            adjList[dest].push_back(source); 
        }

        int result = dfs(adjList, hasApple, 0, -1);

        return result;
    }
};
class Solution {
public:

    void dfs(vector<bool> &visited, vector<vector<int>> &adjList, stack<int> &bucket, int node, bool &rootFound) {

        if (node == 0) {
            rootFound = true;
            return;
        }

        visited[node] = true;

        for (auto neighbor : adjList[node]) {
            if (visited[neighbor] == true) continue;
            dfs(visited, adjList, bucket, neighbor, rootFound);

            if (rootFound) {
                bucket.push(neighbor);
                break;
            }
        }

    }

    int dfsRoot(
        vector<bool> &visited, 
        vector<vector<int>> &adjList, 
        vector<int> &mark,
        vector<int> &amount, 
        int node,
        int currentMove) {

        visited[node] = true;
        int result = amount[node];

        if (currentMove == mark[node]) {
            result /= 2;
        } else if (currentMove > mark[node] && mark[node] != INT_MIN) {
            result = 0;
        }

        int temp = INT_MIN;
        for (auto neighbor : adjList[node]) {
            if (visited[neighbor] == true) continue;
            temp = max(temp, dfsRoot(visited, adjList, mark, amount, neighbor, currentMove + 1));
        }

        if (temp == INT_MIN) return result;
        else return result + temp;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        vector<vector<int>> adjList(edges.size() + 1);

        for (auto edge : edges) {
            int source = edge[0];
            int destination = edge[1];

            adjList[source].push_back(destination);
            adjList[destination].push_back(source); 
        }

        // construct bucket of path bob
        vector<bool> visited(1e5 + 1, false);
        stack<int> bucket;
        bool rootFound = false;
        dfs(visited, adjList, bucket, bob, rootFound);
        bucket.push(bob);

        vector<int> mark(edges.size() + 1, INT_MIN);
        int move = 0;
        while (bucket.size() > 0) {
            mark[bucket.top()] = move;
            bucket.pop();
            move++;
        }

        // run dfs from the root to the the answer
        fill(visited.begin(), visited.end(), false);
        return dfsRoot(visited, adjList, mark, amount, 0, 0);
    }
};
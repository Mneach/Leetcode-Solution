class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adjList;
        unordered_map<int, int> degree;

        for (const auto& pair : pairs) {
            adjList[pair[0]].push_back(pair[1]);
            degree[pair[0]]++;  
            degree[pair[1]]--; 
        }

        int startNode = pairs[0][0];
        for (const auto& [node, deg] : degree) {
            if (deg == 1) {
                startNode = node;
                break;
            }
        }

        vector<int> path = eulerianPath(startNode, adjList);

        vector<vector<int>> result;
        for (int i = path.size() - 1; i > 0; --i) {
            result.push_back({path[i], path[i - 1]});
        }

        return result;
    }

private:
    vector<int> eulerianPath(int startNode, unordered_map<int, vector<int>>& adjList) {
        vector<int> path;
        stack<int> stk;
        stk.push(startNode);

        while (!stk.empty()) {
            int curr = stk.top();
            if (adjList[curr].empty()) {
                path.push_back(curr);
                stk.pop();
            } else {
                int next = adjList[curr].back();
                adjList[curr].pop_back();
                stk.push(next);
            }
        }

        return path;
    }
};

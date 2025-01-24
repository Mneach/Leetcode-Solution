class Solution {
public:

    bool dfs(int index, vector<vector<int>> &graph, vector<int> &answer, vector<bool> &visited) {
        
        if (answer[index] == -1) {
            return false;
        } else if(answer[index] >= 0) {
            return true;
        } else if (visited[index] == true) {
           return false;
        }

        visited[index] = true;
        // meet terminal node
        if (graph[index].size() == 0) {
            answer[index] = index;
            return true;
        } else {
            for (auto node : graph[index]) {
                bool result = dfs(node, graph, answer, visited);

                if (result == false) {
                    answer[index] = -1;
                    return false;
                }
            }

            answer[index] = index;
            return true;
        }
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> bucket(graph.size(), INT_MIN);
        vector<int> answer;
        vector<bool> visited(graph.size(), false);

        for (int i = 0; i < graph.size(); i++) {
            if (visited[i] == true) continue;
            dfs(i, graph, bucket, visited);
        }

        for (int i = 0; i < bucket.size(); i++) {
            if (bucket[i] >= 0) {
                answer.push_back(i);
            }
        }

        return answer;
    }
};
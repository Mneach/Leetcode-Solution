class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int answer = 0;
        vector<vector<int>> adjList(n + 1, vector<int> (n + 1, -1));

        for (auto edge : edges) {
            int source = edge[0];
            int dest = edge[1];

            adjList[source][dest] = 1;
            adjList[dest][source] = 1;
        }

        vector<bool> visited(n + 1, false);

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;

            // running bfs algorithm
            queue<int> q;
            vector<int> visitNode;
            visited[i] = true;
            q.push(i);

            while(q.empty() == false) {
                int current = q.front();
                q.pop();

                visitNode.push_back(current);

                for (int i = 0; i < adjList[current].size(); i++) {
                    if (adjList[current][i] != -1 && visited[i] == false) {
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }

            bool valid = true;
            for (int i = 0; i < visitNode.size() - 1; i++) {
                int source = visitNode[i];
                for (int j = i + 1; j < visitNode.size(); j++) {
                    int dest = visitNode[j];
                    if (adjList[source][dest] == -1) {
                        valid = false;
                        break;
                    }
                }

                if (!valid) break;
            }

            if (valid) {
                answer++;
            }
        }

        return answer;
    }
};
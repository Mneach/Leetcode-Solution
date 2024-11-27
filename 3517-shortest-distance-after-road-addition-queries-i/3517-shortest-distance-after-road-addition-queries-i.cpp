class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {

        vector<vector<int>> adj(n);
        vector<int> answer;

        for(int i = 0; i < n - 1; i++){
            adj[i].push_back(i + 1);
        }

        for(auto q : queries) {
            int source = q[0];
            int dest = q[1];

            adj[source].push_back(dest);
            unordered_map<int,int> visited;

            // node number, cost
            queue<pair<int,int>> queue;
            queue.push({0,0});

            int currAnswer = INT_MAX;
            while(queue.empty() == false) {
                auto [node, cost]  = queue.front();
                queue.pop();

                if(node == n - 1) {
                    currAnswer = min(currAnswer, cost);
                    break;
                }

                for (auto destNode : adj[node]) {
                    if(visited[destNode] > 0) continue;
                    visited[destNode]++;
                    queue.push({destNode, cost + 1});
                }
            }

            answer.push_back(currAnswer);
        }

        return answer;
    }
};
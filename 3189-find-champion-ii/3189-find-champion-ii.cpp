class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for(auto edge : edges){
            int source = edge[0];
            int dest = edge[1];

            adj[source].push_back(dest);
        }

        vector<bool> visited(n);

        for(int i = 0; i < n; i++){

            // bfs start from i
            queue<int> q;
            q.push(i);

            while(q.empty() == false){
                int node = q.front();
                q.pop();

                for(auto connected : adj[node]){
                    if(visited[connected] == false){
                        visited[connected] = true;
                        q.push(connected);
                    }
                }
            }
        }

        int totalValid = 0;
        int answer = -1;
        
        for(int i = 0; i < visited.size(); i++){
            if(visited[i] == false){
                answer = i;
                totalValid++;
            }
        }

        if(totalValid > 1) return -1;

        return answer;
    }
};
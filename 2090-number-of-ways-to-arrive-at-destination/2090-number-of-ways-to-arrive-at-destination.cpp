class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        constexpr int MOD = 1e9 + 7;
        using pii = pair<long long, int>; // {travelTime, node}

        // Build adjacency list
        vector<vector<pii>> graph(n);
        for (const auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            graph[u].emplace_back(v, time);
            graph[v].emplace_back(u, time);
        }

        // Min-Heap (priority queue) for Dijkstra
        priority_queue<pii, vector<pii>, greater<>> pq;
        vector<long long> shortestTime(n, LLONG_MAX);
        vector<int> pathCount(n, 0);
        
        shortestTime[0] = 0;
        pathCount[0] = 1;
        pq.emplace(0, 0); // {time, node}

        while (!pq.empty()) {
            auto [currTime, currNode] = pq.top();
            pq.pop();
            
            if (currTime > shortestTime[currNode]) continue;
            
            for (const auto& [neighbor, roadTime] : graph[currNode]) {
                long long newTime = currTime + roadTime;
                
                if (newTime < shortestTime[neighbor]) {
                    shortestTime[neighbor] = newTime;
                    pathCount[neighbor] = pathCount[currNode];
                    pq.emplace(newTime, neighbor);
                } else if (newTime == shortestTime[neighbor]) {
                    pathCount[neighbor] = (pathCount[neighbor] + pathCount[currNode]) % MOD;
                }
            }
        }

        return pathCount[n - 1];
    }
};
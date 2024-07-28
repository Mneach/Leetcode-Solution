class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adjList(n + 1);

        for(int i = 0; i < edges.size(); i++){
            int source = edges[i][0];
            int dest = edges[i][1];

            adjList[source].push_back(dest);
            adjList[dest].push_back(source);
        }

        queue<pair<int,int>> q;

        vector<int> dist1(n + 1, -1);
        vector<int> dist2(n + 1, -1);

        // start from 1
        q.push({1, 1});
        dist1[1] = 0;

        while(q.empty() == false){
            auto [currentNode, freq] = q.front();
            q.pop();

            int timeTake = -1;

            if(freq == 1) timeTake = dist1[currentNode];
            else timeTake = dist2[currentNode];

            int res = timeTake / change;

            if(res % 2){
                timeTake = change * (res + 1) + time;
            }else{
                timeTake += time;
            }

            cout << timeTake << endl;

            for(auto& next : adjList[currentNode]){
                if(dist1[next] == -1){
                    dist1[next] = timeTake;
                    q.push({next, 1});
                }else if(dist2[next] == -1 && dist1[next] != timeTake){
                    if(next == n) return timeTake;
                    dist2[next] = timeTake;
                    q.push({next, 2});
                }
            }
        }

        return 0;
    }
};
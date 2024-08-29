class Solution {
public:

    void dfs(vector<vector<int>> &adjList, vector<int> &visited, int currentNode){

        visited[currentNode] = 1;

        for(auto node : adjList[currentNode]){
            if(visited[node] == 0){
                dfs(adjList, visited, node);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int total = stones.size();

        vector<vector<int>> adjList(total);

        for(int i = 0; i < total; i++){
            for(int j = i + 1; j < total; j++){
                int source = stones[i][0];
                int dest = stones[i][1];
                int nextSource = stones[j][0];
                int nextDest = stones[j][1];

                if(source == nextSource || dest == nextDest){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        int answer = 0;
        vector<int> visited(total, 0);

        for(int i = 0; i < total; i++){
            if(visited[i] == 0){
                dfs(adjList, visited, i);
                answer++;
            }
        }

        return total - answer;
    }
};
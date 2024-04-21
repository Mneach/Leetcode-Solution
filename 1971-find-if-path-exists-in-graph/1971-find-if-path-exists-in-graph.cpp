class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        if(n == 1) return true;
        
        unordered_map<int,vector<int>> ump;
        vector<bool> visited(n, false);
        
        for(int i = 0; i < edges.size(); i++){
            int start = edges[i][0];
            int end = edges[i][1];
            
            ump[start].push_back(end);
            ump[end].push_back(start);
        }
        
        queue<int> q;
        for(auto data : ump[source]){
            q.push(data);
        }
        
        int answer = false;
        while(q.empty() == false){
            int end = q.front();
            q.pop();
            
            if(visited[end]) continue;
            
            visited[end] = true;
            
            if(end == destination){
                answer = true;
                break;
            }
            
            for(auto data : ump[end]){
                q.push(data);
            }
        }
        
        return answer;
    }
};
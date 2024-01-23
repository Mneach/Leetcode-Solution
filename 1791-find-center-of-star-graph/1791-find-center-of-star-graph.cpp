class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        int answer = 0;
        
        int maximum = 0;
        for(int i = 0; i < edges.size(); i++){
            int start = edges[i][0];
            int end = edges[i][1];
            maximum = max(start, max(maximum, end));
        }
        
        vector<vector<int>> adj(maximum + 1);
        for(int i = 0; i < edges.size(); i++){
            
            int start = edges[i][0];
            int end = edges[i][1];
            
            adj[start].push_back(end);
            adj[end].push_back(start);
        }
        
        for(int i = 1; i <= adj.size(); i++){
            
            if(adj[i - 1].size() == maximum - 1){
                answer = i - 1;
            }
        }
        
        return answer;
    }
};
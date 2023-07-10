class Solution {
public:
    
    void dfs(vector<vector<int>> graph, vector<int> currPath, int currVertex, vector<vector<int>>& answer){
       currPath.push_back(currVertex);
       if(currVertex == graph.size() - 1){    
           answer.push_back(currPath);
           return;
       }else{
           for(int j = 0; j < graph[currVertex].size(); j++){
               dfs(graph, currPath, graph[currVertex][j], answer);
           }    
       }
       
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
       vector<int> currPath;
       vector<vector<int>> answer;
       dfs(graph, currPath, 0, answer);
        
        return answer;
    }
};
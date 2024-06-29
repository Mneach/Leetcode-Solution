class Solution {
public:

    void helper(vector<vector<int>> &bucket, unordered_map<int,int> &visited, int current){
        
        visited[current]++;

        for(auto data : bucket[current]){
            if(visited[data] <= 0) helper(bucket, visited, data);
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> bucket(n);
        vector<vector<int>> answer;

        for(int i = 0; i < edges.size(); i++){
            int source = edges[i][0];
            int destination = edges[i][1];

            bucket[destination].push_back(source);
        }

        for(int i = 0; i < n; i++){
            vector<int> tempAnswer;
            unordered_map<int,int> visited;
            helper(bucket, visited, i);

            for(int j = 0; j < n; j++){
                // need to skip the current node
                if(j != i && visited[j] > 0){
                    tempAnswer.push_back(j);
                }
            }

            answer.push_back(tempAnswer);
        }

        return answer;
    }
};
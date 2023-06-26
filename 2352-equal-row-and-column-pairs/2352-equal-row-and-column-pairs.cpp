class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        int answer = 0;
        
        vector<vector<int>> row(grid.size());
        vector<vector<int>> column(grid.size());
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid.size(); j++){
                row[i].push_back(grid[i][j]);
            }
            
            for(int j = 0; j < grid.size(); j++){
                column[i].push_back(grid[j][i]);
            }
        }
        
        for(int i = 0; i < grid.size(); i++){
            vector<int> currentRow = row[i];
            for(int j = 0; j < grid.size(); j++){
                vector<int> currentColumn = column[j];
                if(currentRow == currentColumn) answer++;
            }
        }
        
        return answer;
    }
};
class Solution {
public:
    
    int answer = 0;
    
    void dfs(vector<vector<int>>& grid, int row, int column, int &current){
        if(row < 0 || column < 0 || row >= grid.size() || column >= grid[0].size()){
            return;
        }
        
        if(grid[row][column] == 0) return;
        
        grid[row][column] = 0;
        
        current++;
        dfs(grid, row - 1, column, current);
        dfs(grid, row + 1, column, current);
        dfs(grid, row, column - 1, current);
        dfs(grid, row, column + 1, current);
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                int current = 0;
                if(grid[i][j] == 1){
                    dfs(grid, i, j, current);
                    answer = max(current, answer);
                }
            }
        }
        
        return answer;
    }
};
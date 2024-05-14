class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int column){
        if(row < 0 || row >= grid.size()){
            return 0;
        }
        
        if(column < 0 || column >= grid[0].size()){
            return 0;
        }
        
        if(grid[row][column] == 0){
            return 0;
        }
        
        int currentCellValue = grid[row][column];\
        grid[row][column] = 0;
        
        int moveTop = dfs(grid, row - 1, column);
        int moveBottom = dfs(grid, row + 1, column);
        int moveRight = dfs(grid, row, column + 1);
        int moveLeft = dfs(grid, row, column - 1);
        
        int result = currentCellValue + max(moveTop, max(moveBottom, max(moveRight, moveLeft)));
        grid[row][column] = currentCellValue;
        return result;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int answer = 0;
        int totalRow = grid.size();
        int totalColumn = grid[0].size();
        
        for(int i = 0; i < totalRow; i++){
            for(int j = 0; j < totalColumn; j++){
                if(grid[i][j] != 0){
                    answer = max(answer, dfs(grid, i, j));
                }
            }
        }
        
        return answer;
    }
};
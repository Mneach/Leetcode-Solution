class Solution {
public:
    
    int result = 0;
    
    int maxMoves(vector<vector<int>>& grid, int currentRow, int currentColumn, int maxRow, int maxColumn, int prev, vector<vector<int>> & dp){
        
        if(currentRow < 0 || currentColumn < 0 || currentRow >= maxRow || currentColumn >=  maxColumn) return 0;
        
        int currentCell = grid[currentRow][currentColumn];
        if(prev >= currentCell) return 0;
        
        if(dp[currentRow][currentColumn] != -1) return dp[currentRow][currentColumn];
        
        int moveTopRight = maxMoves(grid, currentRow - 1, currentColumn + 1, maxRow, maxColumn, currentCell, dp);
        int moveRight = maxMoves(grid, currentRow, currentColumn + 1, maxRow, maxColumn, currentCell, dp);
        int moveBottomRight = maxMoves(grid, currentRow  +  1, currentColumn + 1, maxRow, maxColumn, currentCell, dp);
        
        return dp[currentRow][currentColumn] = max({moveTopRight, moveRight, moveBottomRight}) + 1;
    }
    
    int maxMoves(vector<vector<int>>& grid) {
        
        int maxRow = grid.size();
        int maxColumn = grid[0].size();
        int answer = 0;
        
        vector<vector<int>> dp(maxRow, vector<int>(maxColumn , -1));
        
        for(int i = 0; i < grid.size(); i++){
            int temp = maxMoves(grid, i , 0, maxRow, maxColumn, 0, dp);
            answer = max(temp , answer);
        }
        
        return answer - 1;
    }
};
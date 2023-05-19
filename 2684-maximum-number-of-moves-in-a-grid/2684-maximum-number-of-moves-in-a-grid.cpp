class Solution {
public:
    
    int result = 0;
    int dp[1001][1001];
    
    int move(vector<vector<int>>& grid, int currentRow, int currentColumn, int maxRow, int maxColumn, int totalMove){
        
        if(currentRow < 0 || currentColumn < 0 || currentRow >= maxRow || currentColumn >=  maxColumn) return 0;
        
        if(dp[currentRow][currentColumn]) return dp[currentRow][currentColumn];
        
        int currentCell = grid[currentRow][currentColumn];
       
        if(currentRow != 0 && currentColumn != maxColumn - 1){
            if(currentCell < grid[currentRow - 1][currentColumn + 1]){
                result = max(result, move(grid, currentRow - 1, currentColumn + 1, maxRow, maxColumn, totalMove + 1));
            }
        }
        
        if(currentColumn != maxColumn - 1){
             if(currentCell < grid[currentRow][currentColumn + 1]) {
                result = max(result, move(grid, currentRow, currentColumn + 1, maxRow, maxColumn, totalMove + 1)); 
            }            
        }
        
        if(currentRow != maxRow - 1 && currentColumn != maxColumn - 1) {
            if(currentCell < grid[currentRow + 1][currentColumn + 1]){
                result = max(result, move(grid, currentRow + 1, currentColumn + 1, maxRow, maxColumn, totalMove + 1));
            }
        }
        
        dp[currentRow][currentColumn] = totalMove;
        return dp[currentRow][currentColumn];
    }
    
    int maxMoves(vector<vector<int>>& grid) {
        
        int maxRow = grid.size();
        int maxColumn = grid[0].size();
        
        int answer = 0;
        
        // cout << move(grid, 0 , 0, maxRow, maxColumn, 0) << endl;
        // cout << result << endl;
        
        for(int i = 0; i < grid.size(); i++){
            answer = max(max(answer , move(grid, i , 0, maxRow, maxColumn, 0)), result);
            result = 0;
        }
        
        return answer;
    }
};
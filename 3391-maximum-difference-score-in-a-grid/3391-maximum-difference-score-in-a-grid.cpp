class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int totalRow = grid.size();
        int totalColumn = grid[0].size();   
        int answer = INT_MIN;
        
        vector<vector<int>> dp(totalRow, vector<int>(totalColumn,0));
        
        for(int row = totalRow - 1; row >= 0; row--){
            for(int column = totalColumn - 1; column >= 0; column--){
                int currentCell = grid[row][column];
                
                if(row == totalRow - 1 && column == totalColumn - 1){
                    // basecase
                    dp[row][column] = INT_MIN;
                    
                }else if(row == totalRow - 1 && column == totalColumn - 2){
                    int nextRightCell = grid[row][column + 1];
                    dp[row][column] = nextRightCell - currentCell;
                    
                }else if(row == totalRow - 2 && column == totalColumn - 1){
                    int nextBottomCell = grid[row + 1][column];
                    dp[row][column] = nextBottomCell - currentCell;
                    
                }else if(row == totalRow - 1){
                    // only need to check the right cell of the current cell
                    int nextRightCell = grid[row][column + 1];
                    int nextRightCellDp = dp[row][column + 1];
                    
                    dp[row][column] = max(nextRightCell - currentCell, (nextRightCell - currentCell) + nextRightCellDp);
                    
                }else if(column == totalColumn - 1){
                    // only need to check the bottom cell of the current cell
                    int nextBottomCell = grid[row + 1][column];
                    int nextBottomCellDp = dp[row + 1][column];
                    
                    dp[row][column] = max(nextBottomCell - currentCell, (nextBottomCell - currentCell) + nextBottomCellDp);
                }else{
                    // need to check right cell and the bottom cell
                    int nextRightCell = grid[row][column + 1];
                    int nextRightCellDp = dp[row][column + 1];
                    
                    int nextBottomCell = grid[row + 1][column];
                    int nextBottomCellDp = dp[row + 1][column];
                    
                    int maxRight = max(nextRightCell - currentCell, (nextRightCell - currentCell) + nextRightCellDp);
                    int maxBottom = max(nextBottomCell - currentCell, (nextBottomCell - currentCell) + nextBottomCellDp);
                    
                    dp[row][column] = max(maxRight, maxBottom);
                }
                
                answer = max(answer, dp[row][column]);
            }
        }
        
        return answer;
    }
};
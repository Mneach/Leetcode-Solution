class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        for(int row = 0; row < grid.size(); row++){
            
            for(int col = 0; col < grid[row].size(); col++){
                if(row == 0 && col == 0) continue;
                int currentCell = grid[row][col];

                if(row == 0){
                    grid[row][col] = currentCell + grid[row][col - 1];
                }else if(col == 0){
                    grid[row][col] = currentCell + grid[row - 1][col];
                }else{
                    grid[row][col] = currentCell + min(grid[row][col - 1], grid[row - 1][col]);
                }
            }
        }

        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};


/*

State 
dp[i][i] = mininum sum from [0][0] until [i][i]

Transition
dp[i][i] = current cell + min(top cell, left cell)
dp[0][i] = current cell + left cell
dp[i][0] = current cell + top cell

final subproblem
dp[n][n]

*/
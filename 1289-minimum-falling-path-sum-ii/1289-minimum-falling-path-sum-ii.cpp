class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        
        int minimum1 = -1;
        int minimum2 = -1;
        for(int i = 0; i < grid.size(); i++){
            int result = grid[grid.size() - 1][i];
            int currentPositionInMemo = grid[grid.size() - 1][i];
            
            if(minimum1 == -1 || currentPositionInMemo < dp[grid.size() - 1][minimum1]){
                minimum2 = minimum1;
                minimum1 = i;              
            }else if(minimum2 == -1 || currentPositionInMemo < dp[grid.size() - 1][minimum2]){
                minimum2 = i;
            }
            
            dp[grid.size() - 1][i] = result;
        }
        
        cout << minimum1 << " " << minimum2 << endl;
        
        for(int row = grid.size() - 2; row >= 0; row--){
            int min1 = -1;
            int min2 = -1;
            
            for(int col = 0; col < grid.size(); col++){
                int result = grid[row][col];
                
                // check for cannot get same column
                if(col == minimum1){
                    dp[row][col] = result + dp[row + 1][minimum2];
                }else{
                    dp[row][col] = result + dp[row + 1][minimum1];
                }
                
                // update for get the minimum in the current column
                if(min1 == -1 || dp[row][col] <= dp[row][min1]){
                    min2 = min1;
                    min1 = col;
                }else if(min2 == -1 || dp[row][col] <= dp[row][min2]){
                    min2 = col;
                }
            }
            
            minimum1 = min1;
            minimum2 = min2;
        }
        
//         for(auto data : dp){
//             for(auto d : data){
//                 cout << d << " ";
//             }
//             cout << endl;
//         }
        
        return dp[0][minimum1];
    }
};
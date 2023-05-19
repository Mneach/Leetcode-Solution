class Solution {
public:
    
    int result = 0;
    
    int maxMoves(vector<vector<int>>& grid, int i, int j, int m, int n,int prev, vector<vector<int>> & dp){
       
        if(i < 0 || j < 0 || i >= m || j >=  n) return 0;
        
        int currentCell = grid[i][j];
        
        if(prev >= currentCell) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int moveTopRight = maxMoves(grid, i - 1, j + 1, m, n,  currentCell, dp);
        int moveRight = maxMoves(grid, i, j + 1, m, n, currentCell, dp);
        int moveBottomRight = maxMoves(grid, i  +  1, j + 1, m, n, currentCell, dp);
        
        return dp[i][j] = max({moveTopRight, moveRight, moveBottomRight}) + 1;
    }
    
    int maxMoves(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int answer = 0;
        
        vector<vector<int>> dp(m, vector<int>(n , -1));
        
        for(int i = 0; i < grid.size(); i++){
            int temp = maxMoves(grid, i , 0, m, n, 0, dp);
            answer = max(temp , answer);
        }
        
        return answer - 1;
    }
};
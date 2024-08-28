class Solution {
public:

    int moveY[4] = {1,-1,0,0};
    int moveX[4] = {0,0,1,-1};

    void dfs(int row, int col, vector<vector<int>>& grid){
        if(row < 0 || col < 0 || row == grid.size() || col == grid[0].size() || grid[row][col] == 0)
            return;
        
        grid[row][col] = 0;
        for(int i = 0; i < 4; i++){
            dfs(row + moveY[i], col + moveX[i], grid);
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
       int totalRow = grid1.size();
       int totalColumn = grid1[0].size(); 
       int answer = 0;

       for(int i = 0; i < totalRow; i++){
            for(int j = 0; j < totalColumn; j++){
                if(grid1[i][j] == 0){
                    dfs(i, j, grid2);
                }
            }
       }

       for(int i = 0; i < totalRow; i++){
            for(int j = 0; j < totalColumn; j++){
                if(grid2[i][j] == 1){
                    dfs(i, j, grid2);
                    answer++;
                }
            }
       }

       return answer;
    }
};
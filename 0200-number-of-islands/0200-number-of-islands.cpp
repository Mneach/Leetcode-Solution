class Solution {
public:
    
    int dfs(vector<vector<char>>& grid, int totalRow, int totalColumn, int currentRow, int currentColumn){
        //1. Check if current position out of grid
        if(currentRow > totalRow || currentColumn > totalColumn || currentRow < 0 || currentColumn < 0) return 0;
        else if(grid[currentRow][currentColumn] == '0') return 0; // 3. Not valid or already visited

        int currentValue = 1;
        grid[currentRow][currentColumn] = '0'; // -> mark as visited
            currentValue += dfs(grid, totalRow, totalColumn, currentRow - 1, currentColumn); // move top
        currentValue += dfs(grid, totalRow, totalColumn, currentRow + 1, currentColumn); // move bottom
        currentValue += dfs(grid, totalRow, totalColumn, currentRow, currentColumn -1); // move left
        currentValue += dfs(grid, totalRow, totalColumn, currentRow, currentColumn + 1); // move right

        return currentValue;
    }


    int numIslands(vector<vector<char>>& grid) {
        int answer = 0;

        if(grid.size() == 0) return 0;

        int totalRow = grid.size();
        int totalColumn = grid[0].size();

        for(int i = 0; i < totalRow; i++){
            for(int j = 0; j < totalColumn; j++){
                if(dfs(grid, totalRow - 1, totalColumn - 1, i, j) > 0){
                    answer++;
                }
            }
        }	

        return answer;

    }
};
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int totalRow = grid.size();
        int totalColumn = grid[0].size();
        int totalRowNewGrid = totalRow - 2;
        int totalColumnNewGrid = totalColumn - 2;
        
        vector<vector<int>> newGrid(totalRowNewGrid, vector<int>(totalColumnNewGrid, 0));
        
        for(int i = 0; i < totalRowNewGrid; i++){
            for(int j = 0; j < totalColumnNewGrid; j++){
                
                for(int row = i; row < i + 3; row++){
                    for(int column = j; column < j + 3; column++){
                        newGrid[i][j] = max(newGrid[i][j], grid[row][column]);
                    }
                }
            }
        }
        
        return newGrid;
    }
};
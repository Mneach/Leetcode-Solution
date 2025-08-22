class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minRow = INT_MAX;
        int minCol = INT_MAX;
        int maxRow = -1;
        int maxCol = -1;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }
        
        int resCol = maxCol - minCol;
        int resRow = maxRow - minRow;
        
        return (resRow + 1) * (resCol + 1);
    }
};
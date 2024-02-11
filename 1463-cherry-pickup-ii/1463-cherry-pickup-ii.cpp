class Solution {
public:
    
    int move[3] = {-1 , 0 , 1};
    int memo[101][101][101];
    
    int topDown(int currentRow , int robotColumn1, int robotColumn2, int totalRow , int totalColumn, vector<vector<int>>& grid){

    // check if the robot has passed the last row
    if(currentRow == totalRow) return 0; 
    // make sure robot cannot move outside of grid
    if(robotColumn1 < 0 || robotColumn2 < 0) return 0;
    if(robotColumn1 >= totalColumn || robotColumn2 >= totalColumn) return 0;

    // take value from memo, so we dont need any more calculations
    if(memo[currentRow][robotColumn1][robotColumn2] != -1) return memo[currentRow][robotColumn1][robotColumn2];

    int caluclateMax = 0;

    // Move robot according to the direction and do top down approach
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            caluclateMax = max(caluclateMax, topDown(currentRow + 1, robotColumn1 + move[i], robotColumn2 + move[j], totalRow , totalColumn, grid));
        }
    }
    

    // check whether the 2 robots are in the same cell
    if(robotColumn1 != robotColumn2){
        caluclateMax += grid[currentRow][robotColumn1] + grid[currentRow][robotColumn2];
    }else{
        caluclateMax += grid[currentRow][robotColumn1];
    }
    
    // store the calculation to the memo array
    memo[currentRow][robotColumn1][robotColumn2] = caluclateMax;
    return memo[currentRow][robotColumn1][robotColumn2];
}

    
    int cherryPickup(vector<vector<int>>& grid) {
            
        int n = grid.size();
        int m = grid[0].size();
        memset(memo, -1, sizeof memo);
            
        
        int answer = topDown(0 , 0 , m - 1, n , m, grid);
        
        return answer;
    }
};
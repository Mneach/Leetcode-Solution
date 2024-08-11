class Solution {
public:

    void recursive(vector<vector<int>>& grid, int row, int col, vector<vector<bool>> &visited){
        if(row < 0 || col < 0) return;
        if(row >= grid.size() || col >= grid[0].size()) return;

        if(visited[row][col] == true) return;

        if(grid[row][col] == 0){
            visited[row][col] = true;
            return;
        }

        visited[row][col] = true;
        recursive(grid, row - 1, col, visited);
        recursive(grid, row + 1, col, visited);
        recursive(grid, row, col - 1, visited);
        recursive(grid, row, col + 1, visited);
    }

    int minDays(vector<vector<int>>& grid) {
        
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        // check 0
        bool check = false;
        bool checkZero = true;
        for(int row = 0; row < grid.size(); row++){
            for(int col = 0; col < grid[row].size(); col++){
                if(grid[row][col] == 1 && visited[row][col] == false){
                    if(check) return 0;
                    recursive(grid, row, col, visited);
                    check = true;
                    checkZero = false;
                }
            }
        }

        if(checkZero) return 0;    


        // check 1
        for(int row = 0; row < grid.size(); row++){
            for(int col = 0; col < grid[row].size(); col++){
                if(grid[row][col] == 1){
                    grid[row][col] = 0;

                    visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
                    bool check = false;
                    bool allZero = true;

                    for(int i = 0; i < grid.size(); i++){
                        for(int j = 0; j < grid[0].size(); j++){
                            if(grid[i][j] == 1 && visited[i][j] == false){
                                if(check) return 1;
                                recursive(grid, i, j, visited);
                                check = true;
                                allZero = false;
                            }
                        }
                    }

                    if(allZero) return 1;

                    grid[row][col] = 1;
                }
            }
        }  

        return 2;
    }
};
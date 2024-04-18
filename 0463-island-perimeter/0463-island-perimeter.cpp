class Solution {
public:
 
    int islandPerimeter(vector<vector<int>>& grid) {
        int answer = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                int current = 4;
                
                if(grid[i][j] == 1){
                    
                    // move top
                    if(i - 1 >= 0 && grid[i - 1][j] == 1){
                        current--;
                    }
                    
                    // move bottom
                    if(i + 1 < grid.size() && grid[i + 1][j] == 1){
                        current--;
                    }
                    
                    // move left
                    if(j - 1 >= 0 && grid[i][j - 1] == 1){
                        current--;
                    }
                    
                    // move right
                    if(j + 1 < grid[i].size() && grid[i][j + 1] == 1){
                        current--;
                    }
                    
                    answer += current;
                }
            }
        }
        
        return answer;
    }
};
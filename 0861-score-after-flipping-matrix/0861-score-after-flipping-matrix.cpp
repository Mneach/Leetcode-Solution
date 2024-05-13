class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        
        // looping from row = 0 and column = 0 until row = 0 and column = totalColumn
        // becuase its binary number
        // the most left bit, make the number to be larger
        // so if the left bit is equal to zero, we need to flip to the one
        
        int totalRow = grid.size();
        int totalColumn = grid[0].size();
        
        for(int i = 0; i < totalRow; i++){
            int currentCell = grid[i][0];

            if(currentCell == 0){
                for(int j = 0; j < totalColumn; j++){
                    if(grid[i][j] == 1){
                        grid[i][j] = 0;
                    }else{
                        grid[i][j] = 1;
                    }
                }
            }
        }
        
        // check every column
        // if total zero is more than total one on that column
        // we need to flip that column, to get the maximum value    
        
        for(int column = 1; column < totalColumn; column++){
            
            // count total one and zero on column[i]
            int totalOne = 0;
            int totalZero = 0;
            
            for(int row = 0; row < totalRow; row++){
                if(grid[row][column] == 1){
                    totalOne++;
                }else{
                    totalZero++;
                }
            }
            
            // need to flip the value of column[i], to get the maximum value
            if(totalZero > totalOne){
                for(int row = 0; row < totalRow; row++){
                    if(grid[row][column] == 1){
                        grid[row][column] = 0;
                    }else{
                        grid[row][column] = 1;
                    }
                }
            }
        }
        
        // for(int row = 0; row < totalRow; row++){
        //     for(int column = 0; column < totalColumn; column++){
        //         cout << grid[row][column] << " ";
        //     }
        //     cout << endl;
        // }
        
        // count the answer
        int answer = 0;
        for(int row = 0; row < totalRow; row++){
            for(int column = 0; column < totalColumn; column++){
                if(grid[row][column] == 1){
                    answer += pow(2, (totalColumn - column) - 1);
                }
            }
        }
        
        return answer;
    }
};
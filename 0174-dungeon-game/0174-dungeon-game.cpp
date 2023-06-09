class Solution {
public:
    
    long long min(int a, int b){
        if(a > b) return b;
        else return a;
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int totalRow = dungeon.size();
        int totalColumn = dungeon[0].size();
        
        for(int row = totalRow - 1; row >= 0; row--){
            for(int column = totalColumn - 1; column >= 0; column--){
                
                int currentCell = dungeon[row][column];
                
                if(row == totalRow - 1 && column == totalColumn - 1){
                    dungeon[row][column] = min(0, currentCell);    
                }else if(row == totalRow - 1){
                    dungeon[row][column] = min(0, currentCell + dungeon[row][column + 1]);
                }else if(column == totalColumn - 1){
                    dungeon[row][column] = min(0, currentCell + dungeon[row + 1][column]);
                }else{
                    int right = abs(dungeon[row][column + 1]);
                    int bottom = abs(dungeon[row + 1][column]);
                    
                    if(right > bottom){
                        dungeon[row][column] = min(0, currentCell + dungeon[row + 1][column]);
                    }else{
                        dungeon[row][column] = min(0, currentCell + dungeon[row][column + 1]);
                    }
                }
            }
        }

        return abs(dungeon[0][0]) + 1;
    }
};
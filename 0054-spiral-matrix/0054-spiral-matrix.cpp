class Solution {
public:
    
    bool isValid(int currentColumn, int currentRow, int maxColumn, int maxRow, vector<vector<int>> matrix){
        if(currentColumn < 0 || currentRow < 0) return false;
        else if(currentColumn >= maxColumn || currentRow >= maxRow) return false;
        else if(matrix[currentRow][currentColumn] == -1000) return false;
        else return true;
    }
    
    int getNextRow(int direction, int currentRow){
        if(direction == 1) return currentRow + 1;
        else if(direction == 3) return currentRow - 1;
        
        return currentRow;
    }
    
    int getNextColumn(int direction, int currentColumn){
        if(direction == 0) return currentColumn + 1;
        else if(direction == 2) return currentColumn - 1;
        
        return currentColumn;
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int totalColumn = matrix[0].size();
        int totalRow = matrix.size();
        
        vector<int> answer;
        
        int totalPush = 0;
        int direction = 0;
        // 0 -> right
        // 1 -> bottom
        // 2 -> left
        // 3 -> top
        
        int currentColumn = 0;
        int currentRow = 0;
        int totalCheckMove = 0;
        
        while(totalPush != totalColumn * totalRow){
           
            while(totalCheckMove != 4){
                int nextColumn = getNextColumn(direction, currentColumn);
                int nextRow = getNextRow(direction, currentRow);
                if(isValid(nextColumn, nextRow, totalColumn, totalRow, matrix)){
                    break;
                }else{
                    direction = (direction + 1) % 4;
                }
                totalCheckMove++;
            }
            
            answer.push_back(matrix[currentRow][currentColumn]);
            matrix[currentRow][currentColumn] = -1000;
            currentRow = getNextRow(direction, currentRow);
            currentColumn = getNextColumn(direction, currentColumn);
            totalPush++;
            
            if(totalCheckMove == 4) break;
            
            totalCheckMove = 0;
        }
        
        return answer;
    }
};
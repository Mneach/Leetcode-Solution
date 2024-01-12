class Solution {
public:
    
    bool canPlace(vector<vector<char>> board, int currentRow, int currentColumn, char currentNumber){
        
        //cout << currentRow << " " << currentColumn << " " << currentNumber << endl;
        // check row
        for(int i = 0; i < 9; i++){
            
            if(i == currentRow) continue;
            
            if(board[i][currentColumn] == currentNumber){
                return false;
            }
        }
        
        // check column
        for(int i = 0; i < 9; i++){
            if(i == currentColumn) continue;
            
            if(board[currentRow][i] == currentNumber){
                return false;
            }
        }
        
        // check current 9 x 9 
        int row = 0;
        int column = 0;
        
        if(currentRow >= 3 && currentRow <= 5){
            row = 3;
        }else if(currentRow > 5){
            row = 6;
        }
        
        if(currentColumn >= 3 && currentColumn <= 5){
            column = 3;
        }else if(currentColumn > 5){
            column = 6;
        }
 
        for(int i = row; i < row + 3; i++){
            for(int j = column; j < column + 3; j++){
                if(currentRow == i && currentColumn == j) continue;
               
                if(board[i][j] == currentNumber){
                    return false;
                }
            }
        }
       
        
        return true;
    }
    
    bool recursive(int currentRow, int currentColumn, vector<vector<char>> &board){
        if(currentRow == 9){
            return true;
        }
        
        if(board[currentRow][currentColumn] != '.'){
            
            if(currentColumn == 8){
                currentColumn = 0;
                currentRow += 1;
            }else{
                currentColumn += 1;
            }
            
            return recursive(currentRow, currentColumn, board);
        }else{
            for(int i = 1; i <= 9; i++){

                char currentNumber = (i + '0');

                if(canPlace(board, currentRow, currentColumn, currentNumber)){
                    board[currentRow][currentColumn] = currentNumber;
                    //cout << currentRow << " " << currentColumn << " " << board[currentRow][currentColumn] << endl;

                    int nextRow = currentRow;
                    int nextColumn = currentColumn;
                    if(currentColumn == 8){
                        nextRow += 1;
                        nextColumn = 0;
                    }else{
                        nextColumn += 1;
                    }

                    bool result = recursive(nextRow, nextColumn, board);

                    if(result){
                        return true;
                    }

                    board[currentRow][currentColumn] = '.';
                }

            }
            return false;
        }
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        
        recursive(0, 0, board);
    }
};
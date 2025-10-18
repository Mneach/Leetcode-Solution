class Solution {
public:
   
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                
                if(board[i][j] == '.') {
                    continue;
                }else {
                    
                    // find row
                    for(int k = i + 1; k < board.size(); k++){
                        if(board[k][j] == board[i][j]) {
                            return false;
                        }
                    }
                    
                    // find col
                    for(int k = j + 1; k < board[0].size(); k++){
                        if(board[i][k] == board[i][j]){
                            return false;
                        }
                    }
                }
            }
        }
        
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
               
                int startRow = i * 3;
                int startColumn = j * 3;
                
                vector<int> bucket(10, 0);
                for(int k = startRow; k < startRow + 3; k++){
                    for(int l = startColumn; l < startColumn + 3; l++){
                        
                        if(board[k][l] == '.') continue;
                        
                        bucket[board[k][l] - '0']++;
                    }
                }
                
                for(int i = 0; i < 10; i++){
                    if(bucket[i] > 1) return false;
                }
                
            }
        }
        
        return true;
    }
};
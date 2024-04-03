class Solution {
public:
    
    bool dfs(vector<vector<char>>& board, string word, int row, int column, int index){
        
        if(index == word.length()){
            return true;
        }
        
        if(row < 0 || column < 0) return false;
        else if(row >= board.size() || column >= board[0].size()) return false;
        else if(board[row][column] != word[index]) return false;
        
        // cout << row << " " << column << " " << board[row][column] << " " << word[index] << endl;
        
        board[row][column] = '0';
        int y[] = {0,1,0,-1};
        int x[] = {1,0,-1,0};
        
        bool result = false;
        for(int i = 0; i < 4; i++){
            result = dfs(board, word, row + y[i], column + x[i], index + 1);
            if(result) break;
        }
        
        board[row][column] = word[index];
        
        return result;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(dfs(board, word, i, j , 0)) return true;
            }
        }
        
        return false;
        
    }
};
class Solution {
public:
    
    bool checkValid(vector<vector<int>> mat, int row, int col){
        
        // check current row 
        for(int i = 0; i < mat.size(); i++){
            if(mat[i][col] == 1 && i != row){
                return false;
            }
        }
        
        // check current column
        for(int i = 0; i < mat[0].size(); i++){
            if(mat[row][i] == 1 && i != col){
                return false;
            }
        }
        
        return true;
    }
    
    int numSpecial(vector<vector<int>>& mat) {
        
        int answer = 0;
        
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[i].size(); j++){
                
                if(mat[i][j] == 1 && checkValid(mat, i , j)){
                    answer++;
                }
            }
        }
        
        return answer;
    }
};
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        
        int answer = INT_MAX;
        
        for(int i = matrix.size() - 1; i >= 0; i--){
            for(int j = 0; j < matrix[0].size(); j++){
                if(i == matrix.size() - 1){
                    dp[i][j] = matrix[i][j];
                }else{
                    int minimum = INT_MAX;
                    int row = i + 1;
                    for(int k = -1; k < 2; k++){
                        int column = j + k;
                        
                        if(column >= 0 && column < matrix.size()){
                            minimum = min(matrix[i][j] + dp[row][column], minimum);
                        }
                    }
                    
                    dp[i][j] = minimum;
                }
            }
        }
        
        for(int i = 0; i < dp[0].size(); i++){
            answer = min(answer, dp[0][i]);
        }
        
        return answer;
    }
};
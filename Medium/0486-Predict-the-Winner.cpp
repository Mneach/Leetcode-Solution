// TIME COMPLEXITY O(N ^ 2)
// SPACE COMPLEXITY O(N ^ 2)

class Solution {
    
public:
    bool PredictTheWinner(vector<int>& nums) {
        int length = nums.size();
        
        int arr[length + 1];
        int dp[length][length];
        
        for (int i = 0; i < length; i++){
            arr[i] = nums[i];
            dp[i][i] = arr[i];
        }
        
        for (int startColumn = 1; startColumn < length; startColumn++)
        {
            for (int row = 0; row < length - startColumn; row++)
            {
                int column = row + startColumn;
                int firstProbability = arr[row] - dp[row + 1][column];
                int secondProbability = arr[column] - dp[row][column - 1];
                
                int result;
                if(firstProbability > secondProbability){
                    result = firstProbability;
                }else{
                    result = secondProbability;
                }
                dp[row][column] = result;
            }
        }
        
        if(dp[0][length - 1] >= 0) return true;
        else return false;
    }
};
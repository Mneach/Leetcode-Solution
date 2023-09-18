class Solution {
public:
    int countVowelStrings(int n) {
        
        vector<vector<int>> dp(n + 1, vector<int>(5, 1));
        
        for(int i = 2; i <= n; i++){
            for(int j = 3; j >= 0; j--){
                int value = dp[i - 1][j] + dp[i][j + 1];
                dp[i][j] = value;
            }
        }
        
        int answer = 0;
        for(int i = 0; i < 5; i++){
            answer += dp[n][i];
        }
        
        return answer;
    }
};
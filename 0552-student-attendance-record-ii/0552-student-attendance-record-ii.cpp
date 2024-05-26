class Solution {
public:
    
    int mod = 1e9 + 7;
   
    int recursive(int n, vector<vector<vector<int>>> &dp, int totalA, int totalL){
        if(totalA == 2 || totalL == 3) return 0;
        
        if(n == 0){
            return 1;
        }
        
        if(dp[n][totalA][totalL] != -1){
            return dp[n][totalA][totalL];
        }
        
        int temp = recursive(n - 1, dp, totalA, 0);
        
        temp = (temp + recursive(n - 1, dp, totalA, totalL + 1)) % mod;
        
        temp = (temp + recursive(n - 1, dp, totalA + 1, 0)) % mod;
        
        return dp[n][totalA][totalL] = temp;
    }
   
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));

            
        if(n == 1) return 3;
        
        return recursive(n, dp, 0, 0);
    }
};
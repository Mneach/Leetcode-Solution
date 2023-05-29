class Solution {
public:
    int climbStairs(int n) {
        
        if(n == 1) return 1;
        else if(n == 2) return 2;
        
        int dp[n];
        dp[0] = 1;
        dp[1] = 2;
        dp[2] = 3;
        
        int increment = 1;
        for(int i = 3; i < n; i++){
            dp[i] = dp[i - 1] + ((dp[i - 1] - dp[i - 2]) + (dp[i - 2] - dp[i - 3]));
            
            increment++;
        }
        
        return dp[n - 1];
    }
};
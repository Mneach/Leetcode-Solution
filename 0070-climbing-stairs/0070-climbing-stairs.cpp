class Solution {
public:
    
    int answer(int n , vector<int>& dp){
        if(n <= 2) return n;
        
        if(dp[n] != -1) return dp[n];
        
        dp[n] = answer(n - 1 , dp) + answer(n - 2, dp);
        return dp[n];
    }
    
    int climbStairs(int n) {
        
        vector<int> dp(n + 1, -1);
        
        return answer(n , dp);
    }
};
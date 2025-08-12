class Solution {
public:
    int numberOfWays(int n, int x) {
        const int MOD = 1e9 + 7;
        
        // dp[i] represents the number of ways to sum to i
        vector<int> dp(n + 1, 0);
        dp[0] = 1;  // Base case: one way to make sum 0
        
        for (int i = 1; i <= n; ++i) {
            long long power = 1;
            // Calculate i^x more efficiently (though for x>1, pow is fine)
            for (int j = 0; j < x; ++j) {
                power *= i;
                if (power > n) break;  // Early exit if it's already too big
            }
            
            if (power > n) continue;  // Skip numbers whose power exceeds n
            
            // Update dp in reverse to avoid overwriting
            for (int j = n; j >= power; --j) {
                dp[j] = (dp[j] + dp[j - power]) % MOD;
            }
        }
        
        return dp[n];
    }
};
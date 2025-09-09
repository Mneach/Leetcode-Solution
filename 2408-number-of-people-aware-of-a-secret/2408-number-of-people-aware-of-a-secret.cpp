class Solution {
public:
    int mod = 1e9 + 7;

    int recursive(int curr, int &n, int &delay, int &forget, vector<int> &dp) {
        if (curr > n) return 0;

        if (dp[curr] != -1) return dp[curr];

        int start = curr + delay;
        int end = curr + forget;
        int answer = 0;

        if (end > n) answer = 1;

        while (start < end && start <= n) {
            answer = (answer + (recursive(start, n, delay, forget, dp) % mod)) % mod; 
            start++;
        }

        dp[curr] = answer % mod;
        return dp[curr];
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n + 1, -1);
        
        int answer = recursive(1, n, delay, forget, dp);

        return answer;
    }
};
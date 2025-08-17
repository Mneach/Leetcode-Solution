class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(n + 1, 0);
        dp[0] = 1;
        double data = 0;;
        if (k > 0) data = 1;

        for (int i = 1; i <= n; i++) {
            dp[i] = data / maxPts;

            if (i < k) {
                data += dp[i];
            }

            if (i - maxPts >= 0 && i - maxPts < k) {
                data -= dp[i - maxPts];
            } 
        }

        double answer = 0.0;
        for (int i = k; i < dp.size(); i++) {
            answer += dp[i];
        }

        return answer;
    }
};
class Solution {
public:

    int recursive(vector<int> &prices, vector<int> &dp, int currentIndex, int profit){

        if(currentIndex + 1 >= prices.size()) return profit;

        if(dp[currentIndex] != INT_MIN) {
            return profit + dp[currentIndex];
        }

        profit -= prices[currentIndex];

        int res = INT_MIN;
        for(int i = currentIndex; i < prices.size() - 1; i++){
            profit += prices[i + 1];
            res = max(res, recursive(prices, dp, i + 3, profit));
            profit -= prices[i + 1];
        }

        dp[currentIndex] = max(res, 0);

        return dp[currentIndex];
    }

    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size(), INT_MIN);
        dp[dp.size() - 1] = 0;

        for(int i = prices.size() - 2; i >= 0; i--){
            dp[i] = max(recursive(prices, dp, i, 0), dp[i + 1]);   
        }

        int res = INT_MIN;
        for(auto data : dp){
            cout << data << " " ;
            res = max(data, res);
        }

        return res;
    }
};
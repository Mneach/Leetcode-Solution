class Solution {
public:
    int change(int amount, vector<int>& coins) {

        vector<int> dp(amount  + 1);
        dp[0] = 1;

        for(auto coin : coins){

            for(int number = coin; number <= amount; number++){
                dp[number] += dp[number - coin];
            }
        }

        return dp[amount];
    }
};
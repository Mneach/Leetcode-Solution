class Solution {
public:
    int change(int amount, vector<int>& coins) {

        if(amount == 0) return 1;

        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
        dp[0][0] = 1;

        int answer = 0;

        for(int i = 1; i <= coins.size(); i++){
            int coin = coins[i - 1];
            dp[i][0] = 1;
            
            for(int j = 1; j <= amount; j++){
                if(j < coin) {
                    dp[i][j] = dp[i - 1][j];
                }else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coin];
                }
            }
        }

        // for(int i = 0; i < dp.size(); i++){
        //     for(int j = 0; j < dp[i].size(); j++){
        //         cout << dp[i][j] << " ";
        //     }

        //     cout << endl;
        // }

        return dp[coins.size()][amount];
    }
};
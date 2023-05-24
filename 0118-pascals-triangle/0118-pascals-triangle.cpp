class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> dp(numRows);
        
        for(int i = 0; i < numRows; i++){
            int currentIndex = 1;
            dp[i].push_back(1);
            while(currentIndex < i){
                cout << dp[i - 1][currentIndex - 1] << endl;
                dp[i].push_back(dp[i - 1][currentIndex - 1] + dp[i - 1][currentIndex]);
                currentIndex++;
            }
            if(i != 0) dp[i].push_back(1);
        }
        
        return dp;
    }
};
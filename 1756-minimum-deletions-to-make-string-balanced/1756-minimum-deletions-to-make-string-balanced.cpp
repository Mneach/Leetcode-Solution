class Solution {
public:
    int minimumDeletions(string s) {
        
        vector<int> dp(s.length() + 1, 0);

        int count = 0;

        for(int i = 0; i < s.length(); i++){

            if(s[i] == 'b'){
                dp[i + 1] = dp[i];
                count++;
            }else{
                dp[i + 1] = min(dp[i] + 1, count);
            }
        }

        return dp[s.length()];
    }
};
class Solution {
public:
    int nthUglyNumber(int n) {
        
        vector<long long int> dp(n + 1);

        dp[0] = 1;
        
        long long int next2, next3, next5;
        next2 = 2;
        next3 = 3;
        next5 = 5;

        long long int index2, index3, index5;
        index2 = index3 = index5 = 0;

        for(int i = 1; i <= n; i++){

            int take = min({next2, next3, next5});

            dp[i] = take;

            if(take == next2){
                index2++;
                next2 = dp[index2] * 2;
            }

            if(take == next3){
                index3++;
                next3 = dp[index3] * 3;
            }

            if(take == next5){
                index5++;
                next5 = dp[index5] * 5;
            }
        }

        for(auto data : dp) cout << data << " ";

        return dp[n - 1];
    }
};
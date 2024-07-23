class Solution {
public:

    int recursive(vector<vector<int>>& pairs, vector<int>& dp, int currentIndex){
        if(currentIndex >= pairs.size()) return 0;

        if(dp[currentIndex] != INT_MIN){
            return dp[currentIndex];
        }

        int res = 0;
        int start = pairs[currentIndex][0];
        int end = pairs[currentIndex][1];
        for(int i = currentIndex + 1; i < pairs.size(); i++){
            int nextStart = pairs[i][0];
            int nextEnd = pairs[i][1];

            if(end < nextStart){
                // cout << currentIndex << " " << i << endl;
                res = max(res, recursive(pairs, dp, i));
            }
        }

        // cout << currentIndex << " " << res << endl;

        dp[currentIndex] = res + 1;

        return dp[currentIndex];
    }

    int findLongestChain(vector<vector<int>>& pairs) {

        sort(pairs.begin(), pairs.end());

        int answer = 1;

        vector<int> dp(pairs.size(), INT_MIN);

        for(int i = 0; i < pairs.size(); i++){
            answer = max(answer, recursive(pairs, dp, i));
        }

        // for(auto data : dp){
        //     cout << data << " " ;
        // }

        return answer;
    }
};
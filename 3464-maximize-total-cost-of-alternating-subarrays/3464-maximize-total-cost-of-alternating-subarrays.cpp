class Solution {
public:

    long long int helper(int currentIndex, int start, int sign, vector<vector<vector<long long>>> &dp, vector<int> &nums){
        if(currentIndex >= nums.size()){
            return 0;
        }

        if(dp[currentIndex][start][sign] != -1e15){
            return dp[currentIndex][start][sign];
        }

        // sign 0 -> decrement
        // sign 1 -> add
        // start 0 -> continue
        // start 1 -> take new

        long long int answer = -1e15;
        if(start == 1){
            // take continue and switch the sign
            answer = max(answer, nums[currentIndex] + helper(currentIndex + 1, 0, 0, dp, nums));
            
            // take continue and keep the sign
            answer = max(answer, nums[currentIndex] + helper(currentIndex + 1, 1, 1, dp, nums));
        }else{
            if(sign == 1){
                // take continue and switch the sign
                answer = max(answer, nums[currentIndex] + helper(currentIndex + 1, 0, 0, dp, nums));

                // take a new and reset the sign
                answer = max(answer, nums[currentIndex] + helper(currentIndex + 1, 1, 1, dp, nums));
            }else{
                // take continue and switch the sign
                answer = max(answer, - nums[currentIndex] + helper(currentIndex + 1, 0, 1, dp, nums));

                // take a new and reset the sign
                answer = max(answer, - nums[currentIndex] + helper(currentIndex + 1, 1, 1, dp, nums));
            }
        }

        dp[currentIndex][start][sign] = answer;

        return dp[currentIndex][start][sign];
    }

    long long maximumTotalCost(vector<int>& nums) {
        vector<vector<vector<long long>>> dp(nums.size(), vector<vector<long long>>(2, vector<long long>(2, -1e15)));


        return helper(0,1,1,dp,nums);
    }
};
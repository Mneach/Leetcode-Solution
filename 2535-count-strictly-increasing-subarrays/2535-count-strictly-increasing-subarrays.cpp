class Solution {
public:
    
    long long int helper(vector<int> &nums, int currentIndex, vector<bool> &dp, int depth){
        if(currentIndex + 1 >= nums.size()) {

            if(dp[currentIndex + 1] == true) return 0;

            dp[currentIndex + 1] = true;
            return depth;
        }

        if(dp[currentIndex] == true) return 0;

        dp[currentIndex] = true;
        if(nums[currentIndex] >= nums[currentIndex + 1]) return depth;

        long long int res = helper(nums, currentIndex + 1, dp, depth + 1);
        return depth + res;
    }

    long long countSubarrays(vector<int>& nums) {
        vector<bool> dp(nums.size(), false);
        long long int answer = 0;

        for(int i = 0; i < nums.size(); i++){
            answer += helper(nums, i, dp, 1);
        }

        return answer;
    }
};
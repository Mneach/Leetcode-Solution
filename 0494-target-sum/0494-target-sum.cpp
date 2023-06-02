class Solution {
public:
    
    int backtracking(vector<int>& nums, vector<unordered_map<int,int>>& dp, int index, int sum, int target){
        if(index == nums.size()) {
            if(target == sum) return 1;
            else return 0;
        }
        
        if(dp[index].count(sum)) return dp[index][sum];
        
        dp[index][sum] = backtracking(nums, dp, index + 1, nums[index] + sum, target) + backtracking(nums, dp, index + 1, sum - nums[index], target);
        return dp[index][sum];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        vector<unordered_map<int,int>> dp(nums.size() + 1);
        
        return backtracking(nums , dp, 0, 0, target);;
    }
};
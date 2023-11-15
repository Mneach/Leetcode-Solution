class Solution {
public:
    
    int recursive(vector<int> &nums, int index, vector<int>& dp){
        if(index >= nums.size()){
            return 0;
        }else if(index >= nums.size() - 2){
            return nums[index];
        }else if(dp[index] != -1){
            return dp[index];
        }else{
            dp[index] = max(recursive(nums, index + 2, dp) + nums[index], recursive(nums, index + 3, dp) + nums[index]);
            
            return dp[index];
        }
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return max(recursive(nums,0,dp), recursive(nums,1,dp)); 
    }
};
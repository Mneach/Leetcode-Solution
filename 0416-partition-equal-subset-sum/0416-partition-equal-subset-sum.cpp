class Solution {
public:

    bool recursive(int size, vector<int> &nums, int subTotal, vector<vector<optional<bool>>> &dp){
        if(subTotal == 0){
            return true;
        }

        if(size == 0 || subTotal < 0){
            return false;
        }

        if(dp[size][subTotal] != nullopt){
            return (dp[size][subTotal] == true);
        }

        bool take = recursive(size - 1, nums, subTotal - nums[size - 1], dp);
        bool skip = recursive(size - 1, nums, subTotal, dp);

        dp[size][subTotal] = take || skip;

        return take || skip;
    }

    bool canPartition(vector<int>& nums) {
        
        int total = 0;
        for(auto data : nums) total += data;

        if(total % 2 == 1) return false;

        int subTotal = total / 2;
        int size = nums.size();
        vector<vector<optional<bool>>> dp(nums.size() + 1, vector<optional<bool>>(subTotal + 1, nullopt));

        return recursive(size, nums, subTotal, dp);
    }
};
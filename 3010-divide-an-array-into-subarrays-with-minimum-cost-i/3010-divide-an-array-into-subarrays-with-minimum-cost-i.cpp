class Solution {
public:
    int minimumCost(vector<int>& nums) {
        
        int answer = nums[0];
        
        sort(nums.begin() + 1, nums.end());
        answer += nums[1] + nums[2];
        
        return answer;
    }
};
class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        int length = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int minimum = INT_MAX;
        for(int i = 0; i < length - 1; i++){
            minimum = min(nums[i + 1] - nums[i], minimum);
        }
        
        return minimum;
    }
};
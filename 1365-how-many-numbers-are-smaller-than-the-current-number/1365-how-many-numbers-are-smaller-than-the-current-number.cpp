class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        int length = nums.size();
        int bucket[102] = {0};
        
        for(auto i : nums) bucket[i + 1]++;
        
        for(int i = 1; i < 102; i++) bucket[i] += bucket[i - 1];
        
        for(int i = 0; i < length; i++){
            nums[i] = bucket[nums[i]];
        }
        
        return nums;
    }
};
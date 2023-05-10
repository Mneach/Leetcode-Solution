class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int length = nums.size();
        int sum = 0;
        
        for(auto num : nums){
            sum += num;
        }
        
        int leftNumber = 0;
        for(int i = 0; i < length; i++){
            if(leftNumber == sum - nums[i] - leftNumber) return i;
            else leftNumber += nums[i];
        }
        
        return -1;
    }
};
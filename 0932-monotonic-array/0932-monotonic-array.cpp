/*

How to solve the problem : 
1. Loop from the first index of nums until the last index of nums
2. We need to check based on the condition that we get from step 1
   - we need to get if the current array is decreasing or increasing
   - if the current array is decresing and nums[i - 1] < nums[i], then return false
   - if the current array is increasing and nums[i - 1] > nums[], then return false

*/
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool isIncreasing = false;
        bool isDecreasing = false;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                continue;
            }

            if (isIncreasing == false && isDecreasing == false) {
                if (nums[i] > nums[i - 1]) {
                    isIncreasing = true;
                } else {
                    isDecreasing = true;
                }
            } else if (isIncreasing && nums[i - 1] > nums[i]) {
                return false;
            } else if (isDecreasing && nums[i - 1] < nums[i]) {
                return false;
            }
        }

        return true;
    }
};
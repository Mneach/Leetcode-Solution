/*

How to solve the problem

# Using sliding window
1. Initialize variables
   - left = 0
   - right = 0
   - result = INT_MAX
   - total = 0
2. while right < nums.size()
   - total += nums[right]
   - while (total >= target)
     - result = min(result, (right - left) + 1)
     - total -= nums[left]
     - increase left pointer by 1
   - increase right pointer by 1 

Time Complexity : O(N)
N -> size of nums

Memory Complexity : O(1)

*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int result = INT_MAX;
        int total = 0;

        while (right < nums.size()) {
            total += nums[right];

            while (total >= target) {
                result = min(result, (right - left) + 1);
                total -= nums[left];
                left++;
            }

            right++;
        }

        if (result == INT_MAX) {
            return 0;
        }

        return result;
    }
};
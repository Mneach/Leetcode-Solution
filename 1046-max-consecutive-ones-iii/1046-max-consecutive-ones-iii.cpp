/*

How to solve the problem

# Using sliding window
1. Initialize variables
   - left = 0
   - right = 0
   - result = 0
2. while right < nums.size()
   - if (nums[right] == 0)
     - we will use k value, so k -= 1
   - while k < 0 && left < right
     - check if nums[left] == 0 
       - add k value by 1
     - increase left pointer by 1
   - get the result using this formula
     - formula : result = max(result, (right - left) + 1)
   - increase right pointer by 1
4. return the result

Time Complexity : O(N)
N -> size of nums

Memory Complexity : O(1)

*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int result = 0;

        while (right < nums.size()) {
            if (nums[right] == 0) {
                k -= 1;
            }

            while (k < 0 && left <= right) {
                if (nums[left] == 0) {
                    k += 1;
                }
                left++;
            }

            result = max(result, (right - left) + 1);

            right++;
        }

        return result;
    }
};
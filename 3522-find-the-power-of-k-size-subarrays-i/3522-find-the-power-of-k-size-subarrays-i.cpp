/*

How to solve the problem

# Using sliding window
1. if k == 1, just return nums
2. initialize variables
   - left = 0
   - right = 1
   - results -> vector<int> 
3. while right < nums.size() 
   - if (nums[left] - nums[left - 1] != 1)
     - move left pointer to the right pointer
       - mark results[left] = -1
     - if ((right - left) + 1 == k)
       - results[left] = nums[right]
       - increase the left pointer by 1
     - increaes the right pointer by 1

Time Complexity : O(N)
N -> size of nums

Memory Complexity : O(1)

*/

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {

        if (k == 1) {
            return nums;
        }

        int left = 0;
        int right = 1;
        vector<int> results(nums.size() - (k - 1), 0);

        while (right < nums.size()) {
            if (nums[right] - nums[right - 1] != 1) {
                while (left < results.size() && left < right) {
                    results[left] = -1;
                    left++;
                }
            }

            int windowSize = (right - left) + 1;
            if (windowSize == k) {
                results[left] = nums[right];
                left++;
            }

            right++;
        }

        return results;
    }
};
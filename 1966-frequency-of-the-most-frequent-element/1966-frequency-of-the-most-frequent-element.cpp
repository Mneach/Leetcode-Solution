/*

How to solve the problem 

# Using Sliding Window
1. Sort nums in asc order
2. initialize variables
   - left = 0
   - right = 0
   - total = 0
   - result = 0
3. while right < nums.size()
   - while (nums[right] * ((right - left) + 1) > total + k)
     - increase the left pointer by 1
     - decrease the total by nums[left]
   - get the result (result = max(result, (right - left) + 1))
   - right++
4. return the result

Time Complexity : O(N)
N -> size of nums

Memory Complexity : O(1)

*/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        long long left = 0;
        long long right = 0;
        long long total = 0;
        long long result = 0;

        sort(nums.begin(), nums.end());

        while (right < nums.size()) {
            total += nums[right];

            while (nums[right] * ((right - left) + 1) > total + k) {
                total -= nums[left];
                left++;
            }

            result = max(result, (right - left) + 1);
            right++;
        }

        return result;
    }
};